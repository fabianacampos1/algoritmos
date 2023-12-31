#include <iostream>
#include <chrono>
#include<random>
#include "linked_list.hpp"

int main() {
    int n;
    std::cin >> n;
    linked_list l1;
    
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        l1.push_back(x);
    }
    auto beg = std::chrono::high_resolution_clock::now();
    l1.clear();
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = end - beg;
    if (not (l1.Size() == 0)) {
        std::cerr << "[ERROR] check clear method!\n";
        exit(1);
    }
    std::cerr << "[INFO] " << "Elapsed time for "
        << "1" << " clear :"
        << elapsed.count() << std::endl;
    return 0;
}