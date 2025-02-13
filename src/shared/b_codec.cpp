#include <cstdint>
#include <cmath>
#include <cstring> 
#include <limits>
#include <memory>
#include <vector>
#include <algorithm>

#include "b_codec.hpp"
#include "matrix.hpp"
#include "fmath/fmath.hpp"

namespace pucch_f2 { 
    Matrix<char>* CODEC_MATRIX = nullptr;

    std::unique_ptr<Matrix<char>> ENCODE_MATRIX_CACHE;
    std::vector<std::unique_ptr<char[]>> PRECOMPUTED_PROBABLES; 
    std::vector<float> SCORE_CACHE;

    void codec_precompute(size_t code_size); 

    void codec_generating_matrix_read() { 
        if (CODEC_MATRIX) {
            delete CODEC_MATRIX;
        }

        CODEC_MATRIX = new Matrix<char>(GENERATING_MATRIX_ROWS, GENERATING_MATRIX_COLS);
    
        FILE *file_matrix = fopen("./codec_matrix.txt", "r"); 
    
        if (!file_matrix) { 
            fprintf(stderr, "func %s \t|\t Error opening file", __FUNCTION__);
            return;
        }
    
        for (int row = 0; row < GENERATING_MATRIX_ROWS; ++row) { 
            char tmp[GENERATING_MATRIX_COLS];

            if (fscanf(file_matrix, "%s", tmp) != 1) { 
                fprintf(stderr, "func %s \t|\t Unknown format type", __FUNCTION__);
                fclose(file_matrix);
                return;    
            } 
            
            for (int col = 0; col < GENERATING_MATRIX_COLS; ++col) { 
                if (tmp[col] == '1' || tmp[col] == '0') {
                    (*CODEC_MATRIX)(row, col) = (tmp[col] == '1') ? 1 : 0;
                } else { 
                    fprintf(stderr, "func %s \t|\t Some error occurred\n", __FUNCTION__);
                    fclose(file_matrix);
                    return; 
                }
            }
        }

        size_t block_sizes[] = {2, 4, 6, 8, 11}; 

        for (size_t bs : block_sizes) { 
            codec_precompute(bs);
        }
    
        fclose(file_matrix);
    }
    
    void codec_memory_clean() { 
        if (CODEC_MATRIX != nullptr) { 
            delete CODEC_MATRIX;
            CODEC_MATRIX = nullptr;
        }
    }

    /**
     * @brief v1_encode
     * Description: Simple encoder, without any optimization
     */
    std::unique_ptr<char[]> v1_encode(const char* data, size_t len, size_t code_size) { 
        Matrix<char> encode_matrix = CODEC_MATRIX->truncate(GENERATING_MATRIX_ROWS, code_size);

        if (len > code_size) { 
            // Handle error if necessary
            return nullptr;
        }

        // Encoding 
        return std::unique_ptr<char[]>(encode_matrix.gf2_multRowVec(data, len)); 
    }

    /**
     * @brief v1_decode 
     * Description: Simple decoder, without any optimization
     */
    std::unique_ptr<char[]> v1_decode(const float* data, size_t len, size_t code_size) {
        if (len > code_size) { 
            // Handle error if necessary
            return nullptr;
        }

        // количество возможных комбинаций (2^k, k - code_size)
        size_t num_comb = 1 << code_size; 

        // наиболее вероятное сообщение
        float max_score = -std::numeric_limits<float>::max();
        std::unique_ptr<char[]> most_probable(new char[code_size]); 

        Matrix<char> encode_matrix = CODEC_MATRIX->truncate(GENERATING_MATRIX_ROWS, code_size);

        // 2^k - 1 переборов
        for (size_t i = 0; i < num_comb; ++i) { 
            // вероятное сообщение
            std::unique_ptr<char[]> probable(new char[code_size]);
        
            for (size_t j = 0; j < code_size; ++j) { 
                probable[j] = ((i >> j) & 1) ? 1 : 0;
            }

            // опорное слово
            std::unique_ptr<char[]> ci(encode_matrix.gf2_multRowVec(probable.get(), code_size)); 

            // скалярное произведение
            float score = 0.0f; 
            for (size_t j = 0; j < encode_matrix.Rows(); ++j) { 
                score += static_cast<float>((ci[j] == -1) ? 0 : 1) * data[j];
            }

            if (score > max_score) { 
                max_score = score; 
                std::memcpy(most_probable.get(), probable.get(), code_size * sizeof(char));
            }
        }

        return most_probable; 
    }

    std::unique_ptr<char[]> conjugate_gradient_decoder(const Matrix<char>& A, const float* b, size_t code_size, float lambda) {
        std::vector<float> x(code_size, 0.0f), r(code_size), p(code_size), Ap(code_size);
        
        for (size_t i = 0; i < code_size; ++i) {
            r[i] = b[i];
            p[i] = r[i];
        }

        float rs_old = 0.0f;
        for (size_t i = 0; i < code_size; ++i) rs_old += r[i] * r[i];

        for (size_t iter = 0; iter < code_size; ++iter) {
            for (size_t i = 0; i < code_size; ++i) {
                Ap[i] = 0;
                for (size_t j = 0; j < code_size; ++j) {
                    Ap[i] += A(i, j) * p[j];
                }
                Ap[i] += lambda * p[i];
            }

            float alpha = rs_old;
            float dot_pAp = 0.0f;
            for (size_t i = 0; i < code_size; ++i) dot_pAp += p[i] * Ap[i];
            alpha /= dot_pAp;

            for (size_t i = 0; i < code_size; ++i) {
                x[i] += alpha * p[i];
                r[i] -= alpha * Ap[i];
            }

            float rs_new = 0.0f;
            for (size_t i = 0; i < code_size; ++i) rs_new += r[i] * r[i];

            if (sqrt(rs_new) < 1e-6) break;

            float beta = rs_new / rs_old;
            for (size_t i = 0; i < code_size; ++i) {
                p[i] = r[i] + beta * p[i];
            }

            rs_old = rs_new;
        }
        
        std::unique_ptr<char[]> result(new char[code_size]);
        for (size_t i = 0; i < code_size; ++i) {
            result[i] = (x[i] > 0.5) ? 1 : 0;
        }
        return result;
    }

    std::unique_ptr<char[]> v2_decode(const float* data, size_t len, size_t code_size) {
        Matrix<char> encode_matrix = CODEC_MATRIX->truncate(GENERATING_MATRIX_ROWS, code_size);
        return conjugate_gradient_decoder(encode_matrix, data, code_size, 0.1f);
    }

    std::unique_ptr<char[]> v3_decode(const float* data, size_t len, size_t code_size) {
        if (len > code_size) return nullptr;

        size_t num_comb = 1 << code_size;

        for (size_t i = 0; i < num_comb; ++i) {
            auto& probable = PRECOMPUTED_PROBABLES[i];
            auto ci = std::unique_ptr<char[]>(ENCODE_MATRIX_CACHE->gf2_multRowVec(probable.get(), code_size));

            float score = 0.0f;
            for (size_t j = 0; j < ENCODE_MATRIX_CACHE->Rows(); ++j) {
                score += static_cast<float>((ci[j] == -1) ? 0 : 1) * data[j];
            }

            SCORE_CACHE[i] = score;
        }

        size_t best_index = std::distance(SCORE_CACHE.begin(), std::max_element(SCORE_CACHE.begin(), SCORE_CACHE.end()));
        return std::unique_ptr<char[]>(PRECOMPUTED_PROBABLES[best_index].get());
    }

    void codec_precompute(size_t code_size) {
        ENCODE_MATRIX_CACHE = std::make_unique<Matrix<char>>(CODEC_MATRIX->truncate(GENERATING_MATRIX_ROWS, code_size));
        
        size_t num_comb = 1 << code_size;
        PRECOMPUTED_PROBABLES.resize(num_comb);
        SCORE_CACHE.resize(num_comb, 0.0f);
    
        for (size_t i = 0; i < num_comb; ++i) {
            PRECOMPUTED_PROBABLES[i] = std::make_unique<char[]>(code_size);
            for (size_t j = 0; j < code_size; ++j) {
                PRECOMPUTED_PROBABLES[i][j] = (i >> j) & 1;
            }
        }
    }   
}
