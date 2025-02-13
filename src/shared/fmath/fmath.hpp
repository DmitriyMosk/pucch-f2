#ifndef FMATH_HPP
#define FMATH_HPP

#include <cstddef>

namespace fmath {
    template <typename T1, typename T2, typename R>
    R scalar_product(const T1* a, const T2* b, size_t len);
}

#include "fmath.tpp"

#endif // FMATH_HPP
