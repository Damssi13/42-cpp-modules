#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>



template <typename T>
void iter(T* addr, size_t len, void (*func)(T&)){
    size_t i = 0;
    while(i < len)
    {
        func(addr[i]);
        i++;
    }
};


#endif