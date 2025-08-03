#include "easyfind.hpp"


int main()
{
    std::vector<int> container;
    container.push_back(12);
    container.push_back(25);
    container.push_back(41);
    container.push_back(34);


    try{
        std::vector<int>::iterator it = easyfind(container, 12);
        std::cout << "NUMBER IS " << *it << std::endl;
    }
    catch(const std::exception &e){
        std::cerr << e.what() << std::endl;
    }

}