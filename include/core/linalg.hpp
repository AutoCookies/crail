#ifndef LINALG_HPP
#define LINALG_HPP

#include "objects/matrix.hpp"

namespace core
{

    // Các phép toán cơ bản
    objects::Matrix add(const objects::Matrix &A, const objects::Matrix &B);
    objects::Matrix subtract(const objects::Matrix &A, const objects::Matrix &B);
    objects::Matrix multiply(const objects::Matrix &A, const objects::Matrix &B);
    objects::Matrix transpose(const objects::Matrix &A);

} // namespace core

#endif // LINALG_HPP
