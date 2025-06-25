#include "Array.hpp"

template <typename T>
Array<T>::Array() : array(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : array(new T[n]()), _size(n) {}

template <typename T>
Array<T>::Array(const Array& other)
{
    *this = other;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T>& other)
{
    if(this == &other)
    {
        delete[] data;
        _size = other._size;
        data = new T(_size);
        for(unsigned int i = 0; i < size; i++)
            data[i] = other.data[i]

    }
    return *this;
}

template <typename T>
Array<T>::~Array()
{
    delete[] data;
}

template <typename T>
T&  Array<T>::operator[](unsigned int index)
{
    if(index >= _size)
        throw std::exception::out
}


unsigned int    Array::size() const;
{
    return _size;
}