#include <iostream>
#include <chrono>
#include <random>
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
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist((l1.size())/2, (l1.size())*3);
    auto beg = std::chrono::high_resolution_clock::now();
    unsigned int m;
    m = l1.size()*0.7;
    unsigned int removed = 0, not_removed = 0;
    for (unsigned int i = 0; i < m; ++i) {
        
        if (l1.get_at(dist(gen)))
            removed++;
        else
            not_removed++;
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = end - beg;
    std::cerr << "[DEBUG] Tried to get " << m << " element(s)\n";
    std::cerr << "[DEBUG] got " << removed << " element(s)\n";
    std::cerr << "[DEBUG] not got " << not_removed << " element(s)\n";
    if (not (l1.size() == n)) {
        std::cerr << "[ERROR] check get_at method!\n";
        exit(1);
    }
    std::cerr << "[INFO] " << "Elapsed time for "
        << removed << " get_at success : "
        << elapsed.count() << std::endl;
    return 0;
}