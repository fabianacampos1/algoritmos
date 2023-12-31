#include <iostream>
#include <chrono>
#include "linked_list.hpp"

int main() {
    int n;
    std::cin >> n;
    linked_list l1;
    auto beg = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        l1.push_back(x);
    }
    std::cout<<l1.Size()<<std::endl;
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = end - beg;
    if ((l1.Size() != n)) {
        std::cerr << "[ERROR] check push_front method!\n";
        exit(1);
    }
    std::cerr << "[INFO] " << "Elapsed time for "
        << n << " pushes back :"
        << elapsed.count() << std::endl;
    return 0;
}