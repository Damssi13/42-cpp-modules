#include "iter.hpp"

template <typename T>
void    add(T& i){
    i += 2;
}



template <typename T>
void   printit(T& i)
{
    std::cout << i <<std::endl;
}



template <typename T>
void    print(T& i){
    std::cout << i << std::endl;
}



int main()
{
    float array[3] = {23.1, 44.43, 12.42};

    iter(array,3,printit< float>);
    iter(array,3,add<float>);
    std::cout << "___________________\n";
    iter(array,3,printit< float>);
}