#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <iostream>
#include "Array.tpp"

template <typename T> 
class Array{
private:
    T   *array;
    unsigned int _size;

public:
    Array();
    Array(unsigned int n);
    Array(const Array& other);
    Array& operator= (const Array& other);
    ~Array();


    void    size() const;
}


#endif
