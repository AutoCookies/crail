#include "objects/tensor.hpp"
#include <iostream>
#include <cassert>

using namespace objects;

void test_creation_and_shape() {
    Tensor<int> t({2, 3});
    auto shape = t.getShape();
    assert(shape.size() == 2);
    assert(shape[0] == 2);
    assert(shape[1] == 3);
    std::cout << "✅ test_creation_and_shape passed\n";
}

void test_access_and_modify() {
    Tensor<int> t({2, 2});
    t(0, 0) = 10;
    t(1, 1) = 20;

    assert(t(0, 0) == 10);
    assert(t(1, 1) == 20);
    std::cout << "✅ test_access_and_modify passed\n";
}

void test_out_of_bounds() {
    Tensor<int> t({2, 2});
    bool thrown = false;
    try {
        t(2, 0) = 5; // ngoài biên
    } catch (const std::out_of_range& e) {
        thrown = true;
    }
    assert(thrown);
    std::cout << "✅ test_out_of_bounds passed\n";
}

void test_flat_print() {
    Tensor<int> t({2, 2});
    t(0, 0) = 1;
    t(0, 1) = 2;
    t(1, 0) = 3;
    t(1, 1) = 4;
    std::cout << "Tensor flat print: ";
    t.printFlat(); // dự kiến: 1 2 3 4
    std::cout << "✅ test_flat_print passed\n";
}

int main() {
    test_creation_and_shape();
    test_access_and_modify();
    test_out_of_bounds();
    test_flat_print();
    std::cout << "🎉 All Tensor tests passed!\n";
    return 0;
}
