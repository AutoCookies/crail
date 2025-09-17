#include <iostream>
#include "objects/tensor.hpp"

using namespace objects;

int main() {
    // Tạo tensor 3D (2 x 3 x 4)
    Tensor<float> t({2, 3, 4});

    // Gán một vài giá trị
    t(0, 0, 0) = 1.0f;
    t(0, 1, 2) = 2.5f;
    t(1, 2, 3) = 42.0f;

    // In giá trị đơn lẻ
    std::cout << "t(0,0,0) = " << t(0,0,0) << "\n";
    std::cout << "t(0,1,2) = " << t(0,1,2) << "\n";
    std::cout << "t(1,2,3) = " << t(1,2,3) << "\n";

    // In toàn bộ tensor (flatten)
    std::cout << "\nTensor (flatten view):\n";
    t.printFlat();

    // Lấy shape
    auto shape = t.getShape();
    std::cout << "\nShape: (";
    for (size_t i = 0; i < shape.size(); i++) {
        std::cout << shape[i];
        if (i < shape.size() - 1) std::cout << ", ";
    }
    std::cout << ")\n";

    return 0;
}
