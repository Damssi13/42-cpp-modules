#include "PmergeMe.hpp"


int main(int ac, char **av)
{
    if(ac < 2)
    {
        std::cerr << "Error: Unvalid number of arguments\n";
        return 1;
    }
    try{
        PmergeMe test1;
        test1.parse(ac, av);
        test1.sort();
    }
    catch(std::runtime_error& e)
    {
        std::cerr << e.what();
    }
}