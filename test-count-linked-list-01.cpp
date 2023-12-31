#include <iostream>
#include <chrono>
#include<random>
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
    unsigned finded =0;
     unsigned not_finded =0;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist((l1.Size())/2, (l1.Size())*3);
    auto beg = std::chrono::high_resolution_clock::now();
    for (unsigned int i = 0; i < l1.Size(); ++i)
    { 
        if(l1.count(dist(gen)) == 0){
            not_finded++;
        } else{
            finded++;
        }
       
        
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = end - beg;
    std::cerr << "[INFO] " << "Elapsed time for count:  "
        << elapsed.count() << std::endl;
    std::cout<<"counted: "<< finded<< std::endl;
    std::cout<<"Not counted: "<< not_finded << std::endl;
    return 0;
}