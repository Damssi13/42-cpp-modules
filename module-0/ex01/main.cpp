#include "PhoneBook.hpp"


int main()
{
    PhoneBook book;

    while(true)
    {
        std::string input;
        std::cout << "Enter a command: ";


        if(!std::getline(std::cin, input) || std::cin.eof())
        {
            std::cout << "\nExited\n"; 
            exit(1);
        }
        input = removeWhiteSpace(input, input.size());
        if(input == "SEARCH")
        {
            book.search();
        }
        else if(input == "ADD")
        {
            book.add();
        }
        else if(input == "EXIT")
        {
            std::cout << "Good Bye, Contacts lost to the void\n";    
            break ;
        }
        else
            std::cout << "Try Again" << std::endl;
    }
    exit(0);
}