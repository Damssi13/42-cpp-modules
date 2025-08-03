#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <exception>
#include <algorithm>

template <typename T>
typename T::iterator   easyfind(T &container, int y)
{
    for(typename T::iterator it = container.begin() ; it != container.end(); it++)
    {
        if(*it == y)
            return it;
    }
    throw(std::runtime_error("Not found !"));

}


#endif