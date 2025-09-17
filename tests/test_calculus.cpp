#include <iostream>
#include <cassert>
#include <cmath>
#include "core/calculus.hpp"

using namespace core;

void test_derivative()
{
    auto f = [](double x) { return x * x * x; }; // f(x) = x^3
    double d = derivative(f, 2.0); // f'(x) = 3x^2 => f'(2) = 12
    assert(std::fabs(d - 12.0) < 1e-3);

    std::cout << "test_derivative passed ✅\n";
}

void test_second_derivative()
{
    auto f = [](double x) { return std::sin(x); }; // f(x)=sin(x), f''(x) = -sin(x)
    double d2 = second_derivative(f, M_PI / 2);    // f''(pi/2) = -1
    assert(std::fabs(d2 - (-1.0)) < 1e-3);

    std::cout << "test_second_derivative passed ✅\n";
}

void test_gradient()
{
    auto f = [](const std::vector<double> &v) {
        // f(x,y) = x^2 + y^2
        return v[0] * v[0] + v[1] * v[1];
    };
    std::vector<double> point = {3.0, 4.0};
    auto grad = gradient(f, point);

    // grad f(x,y) = (2x, 2y) => (6, 8)
    assert(std::fabs(grad[0] - 6.0) < 1e-3);
    assert(std::fabs(grad[1] - 8.0) < 1e-3);

    std::cout << "test_gradient passed ✅\n";
}

int main()
{
    test_derivative();
    test_second_derivative();
    test_gradient();

    std::cout << "All calculus tests passed 🎉\n";
    return 0;
}
