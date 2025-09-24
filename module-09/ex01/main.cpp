#include "RPN.hpp"


int main(int ac, char **av)
{
    if(ac != 2)
    {
        std::cerr << "Unvalid usage: ./RPN \"inverted Polish mathematical expression\"\n";
        return(1);
    }

    try{
        RPN test;
        test.processExpresstion(av[1]);
    }
    catch(std::runtime_error& e)
    {
        std::cerr << e.what();
    }
}