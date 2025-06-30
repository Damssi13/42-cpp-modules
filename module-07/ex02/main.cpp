#include "Array.hpp"

int main()
{
    std::cout << "-------Testing empty array---------\n";
    Array<int> emptyArray;
    std::cout << "Empty array size: " << emptyArray.size() << std::endl;

    std::cout << "\n-------Testing parameterized array---------\n";
    Array<int> fullArray(4);
    std::cout << "Full array size: " << fullArray.size() << std::endl;

    
    for(unsigned int i = 0; i < fullArray.size(); i++)
    {
        fullArray[i] = i * 2;
    }
    std::cout << "\n-------Displaying the content---------\n";
    for(unsigned int i = 0; i < fullArray.size(); i++)
    {
        std::cout << fullArray[i] << " ";
    }

    std::cout << "\n\n-------Testing Copy constructor---------\n";
    Array<int> copy(fullArray);
    std::cout << "Copy array size: " << copy.size() << std::endl;
    
    std::cout << "\n-------Modifiying The content---------\n";
    copy[1] = 99;
    for(unsigned int i = 0; i < copy.size(); i++)
    {
        std::cout << copy[i] << " ";
    }

    std::cout << "\n\n-------Testing subscript operator---------\n";
    try{
        fullArray[4] = 7;
    }
    catch(std::exception &e){   
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n-------Testing String type---------\n";
    Array<std::string> string(3);
    string[0] = "hello ";
    string[1] = "there ";
    string[2] = "bro !";
    for(unsigned int i = 0; i < string.size(); i++)
    {
        std::cout << string[i] << " ";
    }

}
