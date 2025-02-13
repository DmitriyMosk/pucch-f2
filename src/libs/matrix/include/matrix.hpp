#include <stddef.h>
#include <memory>  // for std::unique_ptr

#ifndef _LIB_MATRIX 
#define _LIB_MATRIX

template <typename T> 
using m_slice = T; 

template <typename T> 
class Matrix { 
public: 
    Matrix(size_t rows, size_t cols);

    T& operator()       (size_t row, size_t col);
    const T& operator() (size_t row, size_t col) const;

    std::unique_ptr<m_slice<T>[]>  sliceRow(size_t rowNumber);

    Matrix<T>    truncate(size_t rows, size_t cols) const;

    size_t Rows() const;
    size_t Cols() const;  

    std::unique_ptr<Matrix<T>>      mult   (const Matrix<T>& other)        const;
    std::unique_ptr<m_slice<T>[]>   multArr(const T* other, size_t len)    const;

    // gf2
    std::unique_ptr<Matrix<T>>      gf2_mult   (const Matrix<T>& other)        const;
    std::unique_ptr<m_slice<T>[]>   gf2_multArr(const T* other, size_t len)    const;

    //gf2 col
    std::unique_ptr<m_slice<T>[]>   gf2_multColVec(const T* colVec, size_t len) const;
    std::unique_ptr<m_slice<T>[]>   gf2_multRowVec(const T* rowVec, size_t len) const;

protected:  
    std::unique_ptr<T[]> matrix;  // Use unique_ptr for automatic memory management
    size_t rows_; 
    size_t cols_; 
};

template class Matrix<char>;

#endif 
