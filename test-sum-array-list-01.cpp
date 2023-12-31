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
    unsigned sumed =0;
     unsigned not_sumed =0;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist((l1.size())/2, (l1.size())*3);
    auto beg = std::chrono::high_resolution_clock::now();
    for (unsigned int i = 0; i < l1.size(); ++i)
    { 
        if(l1.count(dist(gen)) == 0){
            not_sumed++;
        } else{
            sumed++;
        }
       
        
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = end - beg;
    std::cerr << "[INFO] " << "Elapsed time for count:  "
        << elapsed.count() << std::endl;
    std::cout<<"counted: "<< sumed<< std::endl;
    std::cout<<"Not counted: "<< not_sumed << std::endl;
    return 0;
}