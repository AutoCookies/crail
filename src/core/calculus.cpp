#include "core/calculus.hpp"
#include <vector>

namespace core
{
    double derivative(const std::function<double(double)> &f, double x, double h)
    {
        return (f(x + h) - f(x - h)) / (2.0 * h);
    }

    double second_derivative(const std::function<double(double)> &f, double x, double h)
    {
        return (f(x + h) - 2.0 * f(x) + f(x - h)) / (h * h);
    }

    std::vector<double> gradient(const std::function<double(const std::vector<double> &)> &f,
                                 const std::vector<double> &x, double h)
    {
        size_t n = x.size();
        std::vector<double> grad(n);

        for (size_t i = 0; i < n; ++i)
        {
            std::vector<double> x1 = x, x2 = x;
            x1[i] += h;
            x2[i] -= h;
            grad[i] = (f(x1) - f(x2)) / (2.0 * h);
        }

        return grad;
    }
}
