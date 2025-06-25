#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>
#include <iostream>

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


    unsigned int    size() const;
    T&  operator[](unsigned int index);
};

#include "Array.tpp"

#endif
