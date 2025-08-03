#ifndef SHARMOLA
#define SHARMOLA

#include <iostream>
#include <vector>
#include <exception>
#include <algorithm>

template <typename T>
typename T::iterator   easyfind(T &container, int y)
{

    typename T::iterator it = std::find(container.begin(), container.end(), y);

    if(it != container.end())
        return it;
    else
        throw std::runtime_error("Not Found !");



}

#endif