#include "iter.hpp"

template <typename T>
void    add(T& x){
    x++;
}

template <typename T>
void    print(T& x){
    std::cout << x << std::endl;
}

int main()
{
    int array[3] = {13,15,19};

    iter(array,3,print<int>);

    std::cout << 
}