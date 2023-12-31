#include <iostream>
#include <chrono>
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
     for (unsigned int i = 0; i < (unsigned int)(n/2); ++i) {
         l1.pop_front();
     }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = end - beg;
    std::cerr << "[INFO] " << "Elapsed time for pop_front:  "
        << elapsed.count() << std::endl;
    return 0;
}