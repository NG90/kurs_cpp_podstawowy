#include "vectorFunctions.hpp"

#include <iostream>

std::vector<std::shared_ptr<int>> generate(int count) {
    std::vector<std::shared_ptr<int>> resultVector{};

    if (count < 0) {
        return resultVector;
    }

    resultVector.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        resultVector.emplace_back(std::make_shared<int>(i));
    }
    return resultVector;
}

void print(const std::vector<std::shared_ptr<int>>& sharedPointersVector) {
    for (const auto& el : sharedPointersVector) {
        std::cout << *el << " | ";
    }
    std::cout << '\n';
}

void add10(const std::vector<std::shared_ptr<int>>& sharedPointersVector) {
    for (auto& el : sharedPointersVector) {
        if (el) {
            *el += 10;
        }
    }
}

void sub10(int* const element) {
    if (element) {
        *element -= 10;
    }
}

void sub10(const std::vector<std::shared_ptr<int>>& sharedPointersVector) {
    for (auto& el : sharedPointersVector) {
        if (el) {
            sub10(el.get());
        }
    }
}