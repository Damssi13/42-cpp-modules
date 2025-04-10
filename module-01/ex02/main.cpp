#include <iostream>
#include <string>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout << "Memory address of str =            " << &str << std::endl;
    std::cout << "Memory address held by stringPTR = " << stringPTR << std::endl;
    std::cout << "Memory address held by stringREF = " << &stringREF << std::endl;;

    std::cout << "Value of str =       " << str << std::endl;;
    std::cout << "Value of stringPTR = " << *stringPTR << std::endl;
    std::cout << "Value of stringREF = " << stringREF << std::endl;
    
}