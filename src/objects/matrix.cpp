#pragma once
#include <vector>
#include <iostream>
#include <stdexcept>

namespace objects
{

    class Matrix
    {
    private:
        size_t rows, cols;
        std::vector<std::vector<double>> data;

    public:
        Matrix(size_t r, size_t c, double init = 0.0)
            : rows(r), cols(c), data(r, std::vector<double>(c, init)) {}

        size_t getRows() const { return rows; }
        size_t getCols() const { return cols; }

        double &operator()(size_t r, size_t c)
        {
            if (r >= rows || c >= cols)
                throw std::out_of_range("Index out of range");
            return data[r][c];
        }

        double operator()(size_t r, size_t c) const
        {
            if (r >= rows || c >= cols)
                throw std::out_of_range("Index out of range");
            return data[r][c];
        }

        void print() const
        {
            for (size_t i = 0; i < rows; i++)
            {
                for (size_t j = 0; j < cols; j++)
                {
                    std::cout << data[i][j] << " ";
                }
                std::cout << "\n";
            }
        }
    };

} // namespace core
