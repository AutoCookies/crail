#include <iostream>
#include "core/calculus.hpp"

using namespace core;

int main()
{
    auto f1 = [](double x) { return x * x * x; };
    std::cout << "f'(2) ~ " << derivative(f1, 2.0) << "\n";        // ~ 12
    std::cout << "f''(2) ~ " << second_derivative(f1, 2.0) << "\n"; // ~ 12

    auto f2 = [](const std::vector<double> &v) {
        return v[0] * v[0] + v[1] * v[1]; // f(x,y) = x^2 + y^2
    };
    std::vector<double> point = {3.0, 4.0};
    auto grad = gradient(f2, point);
    std::cout << "grad f(3,4) = (" << grad[0] << ", " << grad[1] << ")\n"; // (6,8)

    return 0;
}
