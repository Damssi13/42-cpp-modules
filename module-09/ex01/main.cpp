#include "RPN.hpp"


int main(int ac, char **av)
{
    if(ac != 2)
    {
        std::cerr << "Unvalid usage: ./RPN \"inverted Polish mathematical expression\"\n";
        return(1);
    }

    RPN test;
    test.processExpresstion(av[1]);
}