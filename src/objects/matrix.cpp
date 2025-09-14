#include "objects/matrix.hpp"

namespace objects {

// ===== Constructors =====
Matrix::Matrix() : rows(0), cols(0) {}

Matrix::Matrix(size_t r, size_t c, double initVal)
    : rows(r), cols(c), data(r, std::vector<double>(c, initVal)) {}

Matrix::Matrix(const std::vector<std::vector<double>>& values)
    : rows(values.size()), cols(values.empty() ? 0 : values[0].size()), data(values) {
    for (const auto& row : values) {
        if (row.size() != cols) {
            throw std::invalid_argument("All rows must have the same number of columns.");
        }
    }
}

// ===== Getters =====
size_t Matrix::rowCount() const { return rows; }
size_t Matrix::colCount() const { return cols; }

// ===== Access elements =====
double& Matrix::at(size_t r, size_t c) {
    if (r >= rows || c >= cols) throw std::out_of_range("Index out of range");
    return data[r][c];
}

const double& Matrix::at(size_t r, size_t c) const {
    if (r >= rows || c >= cols) throw std::out_of_range("Index out of range");
    return data[r][c];
}

// ===== Utility =====
void Matrix::print(std::ostream& os) const {
    for (const auto& row : data) {
        for (double val : row) {
            os << val << " ";
        }
        os << "\n";
    }
}

std::vector<std::vector<double>> Matrix::getData() const {
    return data;
}

// ===== Operators =====
Matrix Matrix::operator+(const Matrix& other) const {
    if (rows != other.rows || cols != other.cols)
        throw std::invalid_argument("Matrix dimensions must agree for addition.");

    Matrix result(rows, cols);
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            result.at(i, j) = data[i][j] + other.data[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator-(const Matrix& other) const {
    if (rows != other.rows || cols != other.cols)
        throw std::invalid_argument("Matrix dimensions must agree for subtraction.");

    Matrix result(rows, cols);
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            result.at(i, j) = data[i][j] - other.data[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator*(const Matrix& other) const {
    if (cols != other.rows)
        throw std::invalid_argument("Matrix dimensions must agree for multiplication.");

    Matrix result(rows, other.cols, 0.0);
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < other.cols; j++) {
            for (size_t k = 0; k < cols; k++) {
                result.at(i, j) += data[i][k] * other.data[k][j];
            }
        }
    }
    return result;
}

Matrix Matrix::operator*(double scalar) const {
    Matrix result(rows, cols);
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            result.at(i, j) = data[i][j] * scalar;
        }
    }
    return result;
}

Matrix Matrix::operator/(double scalar) const {
    if (scalar == 0.0) throw std::invalid_argument("Division by zero.");

    Matrix result(rows, cols);
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            result.at(i, j) = data[i][j] / scalar;
        }
    }
    return result;
}

// ===== Transpose =====
Matrix Matrix::transpose() const {
    Matrix result(cols, rows);
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            result.at(j, i) = data[i][j];
        }
    }
    return result;
}

} // namespace objects
