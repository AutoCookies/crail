#include "core/linalg.hpp"
#include <stdexcept>

namespace core
{

    // Nhân ma trận A * B
    Matrix multiply(const Matrix &A, const Matrix &B)
    {
        if (A.getCols() != B.getRows())
        {
            throw std::invalid_argument("Matrix dimensions do not match for multiplication");
        }

        Matrix result(A.getRows(), B.getCols(), 0.0);

        for (size_t i = 0; i < A.getRows(); ++i)
        {
            for (size_t j = 0; j < B.getCols(); ++j)
            {
                double sum = 0.0;
                for (size_t k = 0; k < A.getCols(); ++k)
                {
                    sum += A(i, k) * B(k, j);
                }
                result(i, j) = sum;
            }
        }
        return result;
    }

    // Cộng hai ma trận cùng kích thước
    Matrix add(const Matrix &A, const Matrix &B)
    {
        if (A.getRows() != B.getRows() || A.getCols() != B.getCols())
        {
            throw std::invalid_argument("Matrix dimensions must match for addition");
        }

        Matrix result(A.getRows(), A.getCols(), 0.0);

        for (size_t i = 0; i < A.getRows(); ++i)
        {
            for (size_t j = 0; j < A.getCols(); ++j)
            {
                result(i, j) = A(i, j) + B(i, j);
            }
        }
        return result;
    }

    // Trừ hai ma trận
    Matrix subtract(const Matrix &A, const Matrix &B)
    {
        if (A.getRows() != B.getRows() || A.getCols() != B.getCols())
        {
            throw std::invalid_argument("Matrix dimensions must match for subtraction");
        }

        Matrix result(A.getRows(), A.getCols(), 0.0);

        for (size_t i = 0; i < A.getRows(); ++i)
        {
            for (size_t j = 0; j < A.getCols(); ++j)
            {
                result(i, j) = A(i, j) - B(i, j);
            }
        }
        return result;
    }

    // Chuyển vị ma trận
    Matrix transpose(const Matrix &A)
    {
        Matrix result(A.getCols(), A.getRows(), 0.0);

        for (size_t i = 0; i < A.getRows(); ++i)
        {
            for (size_t j = 0; j < A.getCols(); ++j)
            {
                result(j, i) = A(i, j);
            }
        }
        return result;
    }

} // namespace linalg
