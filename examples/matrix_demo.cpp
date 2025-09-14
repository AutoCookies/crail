#include "core/linalg.hpp"
#include <iostream>

using namespace objects;
using namespace core;

int main()
{
    Matrix A(2, 2, 1.0);
    Matrix B(2, 2, 2.0);

    std::cout << "Matrix A:\n";
    A.print();

    std::cout << "Matrix B:\n";
    B.print();

    std::cout << "A + B:\n";
    add(A, B).print();

    std::cout << "A - B:\n";
    subtract(A, B).print();

    std::cout << "A * B:\n";
    multiply(A, B).print();

    std::cout << "Transpose(A):\n";
    transpose(A).print();

    return 0;
}
