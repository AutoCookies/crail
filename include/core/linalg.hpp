#pragma once
#include "matrix.hpp"

namespace linalg
{
    Matrix add(const Matrix &A, const Matrix &B);
    Matrix subtract(const Matrix &A, const Matrix &B);
    Matrix multiply(const Matrix &A, const Matrix &B);
    Matrix transpose(const Matrix &A);    
}
