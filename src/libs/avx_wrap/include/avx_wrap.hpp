#ifndef _LIB_AVX_WRAP
#define _LIB_AVX_WRAP

#include <immintrin.h>

// hardware methods
namespace _hw_mt { 
    bool is_avx512_supported();
    bool is_avx256_supported();

    
}

#endif 