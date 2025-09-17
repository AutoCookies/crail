#include "objects/tensor.hpp"

namespace objects
{

    // Explicit instantiations (các kiểu dữ liệu thường dùng)
    template class Tensor<int>;
    template class Tensor<float>;
    template class Tensor<double>;

} // namespace objects
