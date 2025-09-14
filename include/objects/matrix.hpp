#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <vector>
#include <iostream>
#include <stdexcept>

namespace objects {

class Matrix {
private:
    std::vector<std::vector<double>> data;
    size_t rows;
    size_t cols;

public:
    // Constructors
    Matrix();
    Matrix(size_t r, size_t c, double initVal = 0.0);
    Matrix(const std::vector<std::vector<double>>& values);

    // Getters
    size_t rowCount() const;
    size_t colCount() const;

    // Access elements
    double& at(size_t r, size_t c);
    const double& at(size_t r, size_t c) const;

    // Utility
    void print(std::ostream& os = std::cout) const;
    std::vector<std::vector<double>> getData() const;

    // Operators
    Matrix operator+(const Matrix& other) const;
    Matrix operator-(const Matrix& other) const;
    Matrix operator*(const Matrix& other) const;
    Matrix operator*(double scalar) const;
    Matrix operator/(double scalar) const;

    Matrix transpose() const;
};

} // namespace objects

#endif // MATRIX_HPP
