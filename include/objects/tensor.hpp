#pragma once
#include <vector>
#include <iostream>
#include <numeric>
#include <stdexcept>

namespace objects {

template <typename T>
class Tensor {
private:
    std::vector<int> shape;      // kích thước mỗi chiều
    std::vector<int> strides;    // bước nhảy để indexing
    std::vector<T> data;         // dữ liệu thực tế

    void computeStrides() {
        strides.resize(shape.size());
        int s = 1;
        for (int i = static_cast<int>(shape.size()) - 1; i >= 0; --i) {
            strides[i] = s;
            s *= shape[i];
        }
    }

    int getIndex(const std::vector<int>& indices) const {
        if (indices.size() != shape.size())
            throw std::invalid_argument("Number of indices does not match tensor rank");
        int idx = 0;
        for (size_t i = 0; i < shape.size(); i++) {
            if (indices[i] < 0 || indices[i] >= shape[i])
                throw std::out_of_range("Index out of bounds");
            idx += indices[i] * strides[i];
        }
        return idx;
    }

public:
    Tensor(const std::vector<int>& shape_) : shape(shape_) {
        computeStrides();
        int totalSize = std::accumulate(shape.begin(), shape.end(), 1, std::multiplies<int>());
        data.resize(totalSize, T{});
    }

    // Truy cập bằng vector indices
    T& at(const std::vector<int>& indices) {
        return data[getIndex(indices)];
    }

    const T& at(const std::vector<int>& indices) const {
        return data[getIndex(indices)];
    }

    // Overload operator() cho tiện
    template <typename... Args>
    T& operator()(Args... args) {
        std::vector<int> indices{args...};
        return at(indices);
    }

    template <typename... Args>
    const T& operator()(Args... args) const {
        std::vector<int> indices{args...};
        return at(indices);
    }

    // Lấy shape
    std::vector<int> getShape() const { return shape; }

    // In tensor (flatten)
    void printFlat() const {
        for (const auto& v : data) std::cout << v << " ";
        std::cout << "\n";
    }
};

} // namespace objects
