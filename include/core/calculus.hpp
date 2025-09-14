#ifndef CORE_CALCULUS_HPP
#define CORE_CALCULUS_HPP

#include <functional>

namespace core
{
    // Đạo hàm bậc nhất tại điểm x (dùng central difference)
    double derivative(const std::function<double(double)> &f, double x, double h = 1e-5);

    // Đạo hàm bậc 2 tại điểm x
    double second_derivative(const std::function<double(double)> &f, double x, double h = 1e-5);

    // Gradient cho hàm nhiều biến f: R^n -> R
    std::vector<double> gradient(const std::function<double(const std::vector<double>&)> &f,
                                 const std::vector<double> &x,
                                 double h = 1e-5);
}

#endif // CORE_CALCULUS_HPP
