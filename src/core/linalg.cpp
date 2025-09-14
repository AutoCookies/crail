#include "core/linalg.hpp"
#include <stdexcept>

namespace core
{

    using objects::Matrix;

    // ----- Cộng -----
    Matrix add(const Matrix &A, const Matrix &B)
    {
        if (A.rowCount() != B.rowCount() || A.colCount() != B.colCount())
            throw std::invalid_argument("Matrix dimensions must agree for addition.");

        Matrix result(A.rowCount(), A.colCount(), 0.0);
        for (size_t i = 0; i < A.rowCount(); i++)
        {
            for (size_t j = 0; j < A.colCount(); j++)
            {
                result.at(i, j) = A.at(i, j) + B.at(i, j);
            }
        }
        return result;
    }

    // ----- Trừ -----
    Matrix subtract(const Matrix &A, const Matrix &B)
    {
        if (A.rowCount() != B.rowCount() || A.colCount() != B.colCount())
            throw std::invalid_argument("Matrix dimensions must agree for subtraction.");

        Matrix result(A.rowCount(), A.colCount(), 0.0);
        for (size_t i = 0; i < A.rowCount(); i++)
        {
            for (size_t j = 0; j < A.colCount(); j++)
            {
                result.at(i, j) = A.at(i, j) - B.at(i, j);
            }
        }
        return result;
    }

    // ----- Nhân -----
    Matrix multiply(const Matrix &A, const Matrix &B)
    {
        if (A.colCount() != B.rowCount())
            throw std::invalid_argument("Matrix dimensions must agree for multiplication.");

        Matrix result(A.rowCount(), B.colCount(), 0.0);
        for (size_t i = 0; i < A.rowCount(); i++)
        {
            for (size_t j = 0; j < B.colCount(); j++)
            {
                double sum = 0.0;
                for (size_t k = 0; k < A.colCount(); k++)
                {
                    sum += A.at(i, k) * B.at(k, j);
                }
                result.at(i, j) = sum;
            }
        }
        return result;
    }

    // ----- Chuyển vị -----
    Matrix transpose(const Matrix &A)
    {
        Matrix result(A.colCount(), A.rowCount(), 0.0);
        for (size_t i = 0; i < A.rowCount(); i++)
        {
            for (size_t j = 0; j < A.colCount(); j++)
            {
                result.at(j, i) = A.at(i, j);
            }
        }
        return result;
    }

} // namespace core
