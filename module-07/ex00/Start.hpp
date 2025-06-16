#ifndef START_HPP
#define START_HPP

#include <iostream>
#include <string>

template <typename T> 
void swap(T &x, T &y){
    T i = x;
    x = y;
    y = i;
}

template <typename T> 
T max(T x, T y){
    if(x == y)
        return y;
    return (x > y) ? x : y; 
}

template <typename T> 
T min(T x, T y){
    if(x == y)
        return y;
    return (x > y) ? y : x;
}

#endif