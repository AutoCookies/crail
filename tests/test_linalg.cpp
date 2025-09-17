#include <iostream>
#include <cassert>
#include "core/linalg.hpp"
#include "objects/matrix.hpp"

using namespace core;
using namespace objects;

void test_add()
{
    Matrix A(2, 2, 1.0); // [[1,1],[1,1]]
    Matrix B(2, 2, 2.0); // [[2,2],[2,2]]
    Matrix C = add(A, B);

    assert(C.at(0, 0) == 3.0);
    assert(C.at(1, 1) == 3.0);

    std::cout << "test_add passed ✅\n";
}

void test_subtract()
{
    Matrix A(2, 2, 5.0);
    Matrix B(2, 2, 3.0);
    Matrix C = subtract(A, B);

    assert(C.at(0, 0) == 2.0);
    assert(C.at(1, 1) == 2.0);

    std::cout << "test_subtract passed ✅\n";
}

void test_multiply()
{
    Matrix A(2, 2, 0.0);
    A.at(0, 0) = 1; A.at(0, 1) = 2;
    A.at(1, 0) = 3; A.at(1, 1) = 4;

    Matrix B(2, 2, 0.0);
    B.at(0, 0) = 2; B.at(0, 1) = 0;
    B.at(1, 0) = 1; B.at(1, 1) = 2;

    Matrix C = multiply(A, B);
    // Expected [[1*2+2*1, 1*0+2*2],
    //           [3*2+4*1, 3*0+4*2]]
    //         = [[4, 4],
    //            [10, 8]]

    assert(C.at(0, 0) == 4.0);
    assert(C.at(0, 1) == 4.0);
    assert(C.at(1, 0) == 10.0);
    assert(C.at(1, 1) == 8.0);

    std::cout << "test_multiply passed ✅\n";
}

void test_transpose()
{
    Matrix A(2, 3, 0.0);
    A.at(0, 0) = 1; A.at(0, 1) = 2; A.at(0, 2) = 3;
    A.at(1, 0) = 4; A.at(1, 1) = 5; A.at(1, 2) = 6;

    Matrix T = transpose(A);

    assert(T.rowCount() == 3);
    assert(T.colCount() == 2);

    assert(T.at(0, 0) == 1);
    assert(T.at(1, 0) == 2);
    assert(T.at(2, 0) == 3);
    assert(T.at(0, 1) == 4);
    assert(T.at(1, 1) == 5);
    assert(T.at(2, 1) == 6);

    std::cout << "test_transpose passed ✅\n";
}

int main()
{
    test_add();
    test_subtract();
    test_multiply();
    test_transpose();

    std::cout << "All linalg tests passed 🎉\n";
    return 0;
}
