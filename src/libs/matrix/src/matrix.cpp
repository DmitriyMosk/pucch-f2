#include "matrix.hpp"
#include <stdexcept>
#include <cstring>

template<typename T>
Matrix<T>::Matrix(size_t rows, size_t cols) : rows_(rows), cols_(cols) {
    matrix = std::make_unique<T[]>(rows_ * cols_);
}

template<typename T>
T& Matrix<T>::operator()(size_t row, size_t col) {
    if (row >= rows_ || col >= cols_ ) {
        throw std::out_of_range("Index out of range"); 
    }

    return matrix[row * cols_ + col];
}

template<typename T>
const T& Matrix<T>::operator()(size_t row, size_t col) const {
    if (row >= rows_ || col >= cols_ ) {
        throw std::out_of_range("Index out of range"); 
    }

    return matrix[row * cols_ + col];
}

template<typename T>
size_t Matrix<T>::Rows() const { 
    return rows_;
}

template<typename T> 
size_t Matrix<T>::Cols() const {
    return cols_; 
}

template<typename T>
std::unique_ptr<Matrix<T>> Matrix<T>::mult(const Matrix<T>& other) const { 
    if (cols_ != other.Rows()) { 
        throw std::invalid_argument("Matrix(A).Cols != Matrix(B).Rows");
    }
    
    auto newMatrix = std::make_unique<Matrix<T>>(rows_, other.Cols());

    for (size_t i = 0; i < rows_; ++i) { 
        for (size_t j = 0; j < other.Cols(); ++j ) { 
            T sum = 0; 
            
            for (size_t k = 0; k < cols_; ++k) { 
                sum += (*this)(i, k) * other(k, j);
            }
            
            (*newMatrix)(i, j) = sum;
        }
    }

    return newMatrix;
}

template<typename T>
std::unique_ptr<m_slice<T>[]> Matrix<T>::multArr(const T* other, size_t len) const { 
    if (len != cols_) { 
        throw std::invalid_argument("Array len must be equal matrix columns count");
    }

    auto newArray = std::make_unique<m_slice<T>[]>(rows_);

    for (size_t i = 0; i < rows_; ++i) { 
        T sum = 0; 
        for (size_t j = 0; j < cols_; ++j) { 
            sum += (*this)(i, j) * other[j];
        }
        newArray[i] = sum; 
    }

    return newArray;
}

// gf2 operations
template<typename T>
std::unique_ptr<Matrix<T>> Matrix<T>::gf2_mult(const Matrix<T>& other) const {
    if (cols_ != other.Rows()) {
        throw std::invalid_argument("Matrix(A).Cols must be equal to Matrix(B).Rows");
    }

    auto result = std::make_unique<Matrix<T>>(rows_, other.Cols());

    for (size_t i = 0; i < rows_; ++i) {
        for (size_t j = 0; j < other.Cols(); ++j) {
            T sum = 0;
            for (size_t k = 0; k < cols_; ++k) {
                sum ^= ((*this)(i, k) & other(k, j));  // XOR instead of addition, AND instead of multiplication in GF(2)
            }
            (*result)(i, j) = sum;
        }
    }

    return result;
}

// gf2 operations
template<typename T>
std::unique_ptr<m_slice<T>[]> Matrix<T>::gf2_multArr(const T* other, size_t len) const {
    if (len != cols_) {
        throw std::invalid_argument("Array length must be equal to the number of matrix cols");
    }

    auto result = std::make_unique<m_slice<T>[]>(rows_);

    for (size_t i = 0; i < rows_; ++i) {
        T sum = 0;
        for (size_t j = 0; j < len; ++j) {
            sum ^= ((*this)(i, j) & other[j]); // XOR for GF(2), AND for multiplication in GF(2)
        }
        result[i] = (sum == 0) ? -1 : 1;
    }

    return result;
}

template<typename T>
std::unique_ptr<m_slice<T>[]> Matrix<T>::gf2_multColVec(const T* colVec, size_t len) const {
    if (len != rows_) {
        throw std::invalid_argument("Column vector length must be equal to the number of matrix rows.");
    }

    auto result = std::make_unique<m_slice<T>[]>(cols_);

    for (size_t j = 0; j < cols_; ++j) {
        T sum = 0;
        for (size_t i = 0; i < len; ++i) {
            sum ^= ((*this)(i, j) & colVec[i]); // XOR for GF(2), AND for multiplication in GF(2)
        }
        result[j] = (sum == 0) ? -1 : 1;
    }

    return result;
}

template<typename T>
std::unique_ptr<m_slice<T>[]> Matrix<T>::gf2_multRowVec(const T* rowVec, size_t len) const {
    if (len != cols_) { // The row vector length corresponds to the number of columns in the matrix
        throw std::invalid_argument("Row vector length must be equal to the number of matrix columns.");
    }

    auto result = std::make_unique<m_slice<T>[]>(rows_);

    for (size_t i = 0; i < rows_; ++i) {
        T sum = 0;
        for (size_t j = 0; j < len; ++j) {
            sum ^= ((*this)(i, j) & rowVec[j]); // XOR for GF(2), AND for multiplication in GF(2)
        }
        result[i] = (sum == 0) ? -1 : 1;
    }

    return result;
}

template<typename T>
std::unique_ptr<T[]> Matrix<T>::sliceRow(size_t rowNumber) {
    if (rowNumber >= rows_) { 
        throw std::out_of_range("Attempt to slice (rowNumber >= rows_)"); 
    }

    auto row = std::make_unique<T[]>(cols_);
    T* ptrEnd = matrix.get() + rowNumber * cols_; 

    std::memcpy(row.get(), ptrEnd, cols_ * sizeof(T)); 

    return row;
}

template<typename T>
Matrix<T> Matrix<T>::truncate(size_t rows, size_t cols) const {
    if (cols_ < cols || rows_ < rows) { 
        fprintf(stderr, "%zu %zu %zu %zu\n", cols_, rows_, cols, rows);
        throw std::out_of_range("Attempt to truncate (_old_cnt_cols < cols || _old_cnt_rows < rows)"); 
    } 

    Matrix<T> newMatrix(rows, cols);

    for (size_t i = 0; i < rows; ++i) { 
        for (size_t j = 0; j < cols; ++j) { 
            newMatrix(i, j) = (*this)(i, j);
        }
    } 

    return newMatrix;
}
