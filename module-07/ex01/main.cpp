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

    iter(array,3,add< int>);

    for(int i = 0;i < 3;i++)
        std::cout << array[i] << std::endl;

}