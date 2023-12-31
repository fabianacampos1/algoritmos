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
    unsigned finded =0;
     unsigned not_finded =0;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist((l1.size())/2, (l1.size())*3);
    unsigned int m;
    m = l1.size()*0.7;
    auto beg = std::chrono::high_resolution_clock::now();
    for (unsigned int i = 0; i < m; ++i)
    { 
        if(l1.find(dist(gen)) == -1){
        not_finded++;
    } else {
        finded++;
    } 
        
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = end - beg;
    std::cerr << "[INFO] " << "Elapsed time for find:  "
        << elapsed.count() << std::endl;
    std::cout<<"Finded: "<< finded<< std::endl;
    std::cout<<"Not Finded: "<< not_finded << std::endl;
    return 0;
}