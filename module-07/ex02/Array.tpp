#include "Array.hpp"

template <typename T>
Array<T>::Array() : array(NULL), _size(0) 
{std::cout << "Default called!\n";}

template <typename T>
Array<T>::Array(unsigned int n) : array(new T[n]()), _size(n) 
{/*std::cout << "Parameterized called!\n";*/}


template <typename T>
Array<T>::Array(const Array& other) : array(NULL), _size(0)
{
    // std::cout << "Copy called!\n";
    *this = other;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T>& other)
{
    if(this != &other)
    {
        delete[] array;
        _size = other._size;
        array = new T[_size];
        for(unsigned int i = 0; i < _size; i++)
            array[i] = other.array[i];
        // std::cout << "Inside condition called called!\n";
    }
    // std::cout << "Operator called!\n";
    return *this;
}

template <typename T>
Array<T>::~Array()
{
    // std::cout << "Destructor Called\n";
    delete[] array;
}

template <typename T>
T&  Array<T>::operator[](unsigned int index)
{
    if(index >= _size)
        throw std::out_of_range("index is out of bound");
    return array[index];
}

template <typename T>
unsigned int    Array<T>::size() const
{
    return _size;
}