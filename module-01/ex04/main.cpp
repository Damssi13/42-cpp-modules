#include <iostream>
#include "Sed.hpp"


int main(int ac, char **av)
{
    Sed file;
    if(ac != 4 || file.setArguments(av[1],av[2],av[3]))
    {
        std::cout << "Error: Unvalid Parameters!\n";
        return 1;
    }   
}