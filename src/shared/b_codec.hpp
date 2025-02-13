#ifndef _LIB_SHARED_B_CODEC
#define _LIB_SHARED_B_CODEC

#include "stdio.h"
#include "stdlib.h"

#define GENERATING_MATRIX_ROWS 20 
#define GENERATING_MATRIX_COLS 13 

namespace pucch_f2 { 
    void codec_generating_matrix_read()                         ;
    void codec_memory_clean()                                   ; 

    void codec_precompute()                                     ;
    // v1 codec
    std::unique_ptr<char[]> v1_encode(const char* data, size_t len, size_t code_size); 
    std::unique_ptr<char[]> v1_decode(const float* data, size_t len, size_t code_size);

    // v2 codec
    std::unique_ptr<char[]> v2_decode(const float* data, size_t len, size_t code_size);
    std::unique_ptr<char[]> v2_decode_with_cache(const float* data, size_t len, size_t code_size);
}

#endif 