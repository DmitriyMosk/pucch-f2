#ifndef FMATH_TPP
#define FMATH_TPP

#include <cstddef>

namespace fmath {
    template <typename T1, typename T2, typename R>
    R scalar_product(const T1* a, const T2* b, size_t len) {
        R result = 0;
        for (size_t i = 0; i < len; ++i) {
            result += static_cast<R>(a[i]) * static_cast<R>(b[i]);
        }
        return result;
    }
}

#endif // FMATH_TPP
