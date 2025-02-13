#ifndef _LIB_SHARED_AWGN
#define _LIB_SHARED_AWGN 

#include <stddef.h>

namespace awgn { 
    using sigma_t = float; 

    std::vector<float> noise_vector(sigma_t sigma, size_t len); 
}

#endif 