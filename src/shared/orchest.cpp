#include <random>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <chrono>
#include <memory>
#include <vector>

#include "orchest.hpp"
#include "b_codec.hpp"

void _launch_codec_orchesting(metrics_t &mt, const std::vector<float>& noise_vector); 
void _generate_data(size_t len, std::unique_ptr<char[]>& data); 
int _validate_data(size_t len, const char* data_src, const char* data_dest);
void _print_metrics(const metrics_t &mt);

void orchest_init(ProccessOrchest &orchest_ini) { 
    pucch_f2::codec_generating_matrix_read(); 

    metrics_t mt; 
    mt.s = orchest_ini.start; 
    mt.require_print = orchest_ini.force_test; 
    mt.decode_errors = 0;
    mt.avg_errors = 0.0f;
    mt.decoding_diff = 0; 
    mt.encoding_diff = 0;
    mt.src_msg_len = 0;
    mt.encoded_block = 20; 
    
    if (orchest_ini.force_test) { 
        std::vector<float> noise_vector = awgn::noise_vector(orchest_ini.start, mt.encoded_block); 
        mt.src_msg_len = orchest_ini.block_size;

        mt.di = std::make_unique<char[]>(mt.src_msg_len);
        _generate_data(mt.src_msg_len, mt.di);
        _launch_codec_orchesting(mt, noise_vector); 

        if (mt.require_print) { 
            _print_metrics(mt); 
        }
    } else { 
        size_t block_sizes[] = {2, 4, 6, 8, 11}; 

        for (size_t bs : block_sizes) { 
            std::string fname = "./stats_v" + std::to_string(orchest_ini.opt_mode) + "_20x" + std::to_string(bs) + ".csv";
            std::ofstream stats(fname, std::ios::app);
            
            if (!stats.is_open()) {
                std::cerr << "File for statistics not open" << std::endl;
                return;
            }

            stats << "b_size,sigma,ber,der,avgencodetime,avgdecodetime\n";

            mt.src_msg_len = bs;

            for (float nsigma = orchest_ini.start; nsigma < orchest_ini.end; nsigma += orchest_ini.step) { 
                mt.s = nsigma;
                std::vector<float> noise_vector = awgn::noise_vector(mt.s, mt.encoded_block); 

                mt.decoding_diff = 0; 
                mt.encoding_diff = 0;
                mt.decode_errors = 0;
                mt.avg_errors = 0.0f;

                mt.di = std::make_unique<char[]>(mt.src_msg_len);
                _generate_data(mt.src_msg_len, mt.di);

                for (int i = 0; i < orchest_ini.sim_iterations; ++i) { 
                    _launch_codec_orchesting(mt, noise_vector, orchest_ini.opt_mode);
                }

                float stats_ber = mt.avg_errors / static_cast<double>(mt.src_msg_len * orchest_ini.sim_iterations); 
                float stats_der = static_cast<float>(mt.decode_errors) / orchest_ini.sim_iterations;
                long double stats_avgencodetime = static_cast<long double>(mt.encoding_diff) / orchest_ini.sim_iterations;
                long double stats_avgdecodetime = static_cast<long double>(mt.decoding_diff) / orchest_ini.sim_iterations;

                stats << mt.src_msg_len << ","
                      << std::setprecision(2) << mt.s << ","
                      << std::setprecision(10) << stats_ber << ","
                      << std::setprecision(10) << stats_der << ","
                      << std::setprecision(20) << stats_avgencodetime << ","
                      << std::setprecision(20) << stats_avgdecodetime << "\n";
            }

            stats.close();
        } 
    }

    pucch_f2::codec_memory_clean(); 
}

void _launch_codec_orchesting(metrics_t &mt, const std::vector<float>& noise_vector, int mode) { 
    auto start = std::chrono::high_resolution_clock::now();
    mt.di_encoded = pucch_f2::v1_encode(mt.di.get(), mt.src_msg_len, mt.src_msg_len); 
    auto end = std::chrono::high_resolution_clock::now();
    mt.encoding_diff += std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

    mt.di_encoded_noised = std::make_unique<float[]>(mt.encoded_block); 
    for (size_t i = 0; i < mt.encoded_block; ++i) { 
        mt.di_encoded_noised[i] = mt.di_encoded[i] + noise_vector[i]; 
    }

    start = std::chrono::high_resolution_clock::now();
    if (mode == 1) {
        mt.di_decoded = pucch_f2::v1_decode(mt.di_encoded_noised.get(), mt.src_msg_len, mt.src_msg_len);
    } else if (mode == 2) { 
        mt.di_decoded = pucch_f2::v2_decode(mt.di_encoded_noised.get(), mt.src_msg_len, mt.src_msg_len);
    } else {
        mt.di_decoded = pucch_f2::v2_decode_with_cache(mt.di_encoded_noised.get(), mt.src_msg_len, mt.src_msg_len);
    }
    end = std::chrono::high_resolution_clock::now(); 
    mt.decoding_diff += std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

    int errs = _validate_data(mt.src_msg_len, mt.di.get(), mt.di_decoded.get());
    if (errs > 0) { 
        mt.decode_errors++;  
        mt.avg_errors += errs; 
    }
}
 
void _generate_data(size_t len, std::unique_ptr<char[]>& data) {
    std::random_device rd;
    std::mt19937 gen(rd());            
    std::uniform_int_distribution<> dis(0, 1);

    for (size_t i = 0; i < len; ++i) {
        data[i] = dis(gen);
    }
}

int _validate_data(size_t len, const char* data_src, const char* data_dest) { 
    int cnt = 0; 
    for (size_t i = 0; i < len; i++) { 
        if (data_src[i] != data_dest[i]) { 
            cnt++; 
        }
    }
    return cnt;
}

void _print_metrics(const metrics_t &mt) { 
    std::cout << "src message[mt.di]: \t\t\t";
    for (size_t i = 0; i < mt.src_msg_len; ++i) { 
        std::cout << (int)mt.di[i]; 
    }
    std::cout << "\n"; 

    std::cout << "encoded[mt.di_encoded]: \t\t";
    for (size_t i = 0; i < mt.encoded_block; ++i) { 
        std::cout << (int)mt.di_encoded[i] << " "; ; 
    }
    std::cout << "\n"; 

    std::cout << "encoded_noised[mt.di_encoded_noised]: \t";
    for (size_t i = 0; i < mt.encoded_block; ++i) { 
        std::cout << mt.di_encoded_noised[i] << " "; 
    }
    std::cout << "\n"; 

    std::cout << "decoded[mt.di_decoded]: \t\t";
    for (size_t i = 0; i < mt.src_msg_len; ++i) { 
        std::cout << (int)mt.di_decoded[i]; 
    }
    std::cout << "\n";
}
