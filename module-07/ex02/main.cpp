#include <iostream>
#include "Array.hpp"
#include <cstdlib>


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

    std::cout << "\n\n-------Testing String type---------\n";
    Array<std::string> string(3);
    string[0] = "hello ";
    string[1] = "there ";
    string[2] = "bro !";
    for(unsigned int i = 0; i < string.size(); i++)
    {
        std::cout << string[i] << " ";
    }

}


// int main()
// {
//     {
//         try
//         {
//             std::cout << "Testing empty array:" << std::endl;
//             Array<int> empty;
//             std::cout << "Empty array size: " << empty.size() << std::endl;
    
//             std::cout << "\nTesting array with size:" << std::endl;
//             Array<int> numbers(5);
//             std::cout << "Array size: " << numbers.size() << std::endl;
    
//             for (unsigned int i = 0; i < numbers.size(); i++)
//             {
//                 numbers[i] = i * 2;
//             }
    
//             std::cout << "Array contents: ";
//             for (unsigned int i = 0; i < numbers.size(); i++)
//             {
//                 std::cout << numbers[i] << " ";
//             }
//             std::cout << std::endl;
    
//             std::cout << "\nTesting copy constructor:" << std::endl;
//             Array<int> copy(numbers);
//             std::cout << "Copy array size: " << copy.size() << std::endl;
//             std::cout << "Copy array contents: ";
//             for (unsigned int i = 0; i < copy.size(); i++)
//             {
//                 std::cout << copy[i] << " ";
//             }
//             std::cout << std::endl;
    
//             numbers[0] = 100;
//             std::cout << "\nAfter modifying original array:" << std::endl;
//             std::cout << "Original array: ";
//             for (unsigned int i = 0; i < numbers.size(); i++)
//             {
//                 std::cout << numbers[i] << " ";
//             }
//             std::cout << std::endl;
//             std::cout << "Copy array: ";
//             for (unsigned int i = 0; i < copy.size(); i++)
//             {
//                 std::cout << copy[i] << " ";
//             }
//             std::cout << std::endl;
    
//             std::cout << "\nTesting assignment operator:" << std::endl;
//             Array<int> assigned = numbers;
//             std::cout << "Assigned array size: " << assigned.size() << std::endl;
//             std::cout << "Assigned array contents: ";
//             for (unsigned int i = 0; i < assigned.size(); i++)
//             {
//                 std::cout << assigned[i] << " ";
//             }
//             std::cout << std::endl;
            
//             std::cout << "\nTesting out of bounds exception:" << std::endl;
//             try
//             {
//                 numbers[10] = 0;
//             }
//             catch (const std::exception &e)
//             {
//                 std::cout << "Exception caught: " << e.what() << std::endl;
//             }
            
//             std::cout << "\nTesting with string type:" << std::endl;
//             Array<std::string> strings(3);
//             strings[0] = "Hello";
//             strings[1] = "World";
//             strings[2] = "!";
//             for (unsigned int i = 0; i < strings.size(); i++)
//             {
//                 std::cout << strings[i] << " ";
//             }
//             std::cout << std::endl;
        
//         }
//         catch (const std::exception &e)
//         {
//             std::cout << "Unexpected exception: " << e.what() << std::endl;
//         }
    
//         return 0;
//     }
// }
// // {
//     //     Array<int> data(0);
//     //     Array<char> _string(0);

// // }