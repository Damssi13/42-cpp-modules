#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>

template <typename T, typename T2>
void iter(T* addr, size_t len, T2 func){
    size_t i = 0;
    while(i < len)
    {
        func(addr[i]);
        i++;
    }
};


#endif