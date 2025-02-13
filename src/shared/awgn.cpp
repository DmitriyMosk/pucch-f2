#include <random>
#include <vector>
#include "awgn.hpp"
namespace awgn { 
    std::vector<float> noise_vector(sigma_t sigma, size_t len) { 
        std::default_random_engine re(std::random_device{}()); 
        std::normal_distribution<float> distr(0.0f, sigma); 

        std::vector<float> vec_n(len); 

        for (size_t i = 0; i < len; ++i) {
            vec_n[i] = distr(re); 
        }

        return vec_n;
    }
}
