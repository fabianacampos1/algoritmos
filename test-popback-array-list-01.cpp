#include <iostream>
#include <chrono>
#include "array_list.hpp"

int main() {
    unsigned int n;
    std::cin >> n;
    array_list l1;
   
    
    for (unsigned int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        l1.push_back(x);
    }
     auto beg = std::chrono::high_resolution_clock::now();
     for (unsigned int i = 0; i < (n/2); ++i) {
         l1.pop_back();
     }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = end - beg;
    std::cerr << "[INFO] " << "Elapsed time for pop_back:  "
        << elapsed.count() << std::endl;
    return 0;
}