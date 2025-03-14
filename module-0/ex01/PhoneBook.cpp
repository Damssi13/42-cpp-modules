#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : contactIndex(0) {}

std::string removeWhiteSpace(std::string str, size_t len)
{
    std::string removed;
    
    for(size_t i = 0; i < len; i++)
    {
        if(str[i] != ' ' && str[i] != '\t')
        removed += str[i];
    }
    return removed;
}

bool    isNumber(std::string input)
{
    for(size_t i = 0; i < input.length();)
    {
        if(isdigit(input[i]))
        i++;
        else
        return false;
    }
    return true;
}

bool    isValid(std::string input)
{
    for(size_t i = 0; i < input.length();)
    {
        if(isprint(input[i]))
        i++;
        else
        return false;
    }
    return true;
}

bool    isChar(std::string input)
{
    for(size_t i = 0; i < input.length();)
    {
        if(isalpha(input[i]))
        i++;
        else
        return false;
    }
    return true;
}

std::string truncate(std::string text)
{
    if(text.length() > 10)
        return (text.substr(0,9) + ".");
    return text;
}

void    addFirstName(Contact *newContact)
{
    std::string input;
    while(true)
    {
        std::cout << "Enter First Name: ";
        if(!getline(std::cin, input))
        {
            if(std::cin.eof())
            {
                std::cout << "Exited\n";
                exit(1);
            }
            std::cout << "Try Again!\n";
        }
        else if(input.empty() || !isChar(input))
            std::cout << "Try Again!\n";
        else
        {
            newContact->setFirstName(input);
            break ;
        }
    }
}

void    addLastName(Contact *newContact)
{
    std::string input;
    while(true)
    {
        std::cout << "Enter Last Name: ";
        if(!getline(std::cin, input))
        {
            if(std::cin.eof())
            {
                std::cout << "Exited\n";
                exit(1);
            }
            std::cout << "Try Again!\n";
        }
        else if(input.empty() || !isChar(input))
            std::cout << "Try Again!\n";
        else
        {
            newContact->setLastName(input);
            break ;
        }
    }
}

void    addNickName(Contact *newContact)
{
    std::string input;
    while(true)
    {
        std::cout << "Enter Nick Name: ";
        if(!getline(std::cin, input))
        {
            if(std::cin.eof())
            {
                std::cout << "Exited\n";
                exit(1);
            }
            std::cout << "Try Again!\n";
        }
        else if(input.empty() || !isValid(input))
            std::cout << "Try Again!\n";
        else
        {
            newContact->setNickName(input);
            break ;
        }
    }
}

void    addPhoneNumber(Contact *newContact)
{
    std::string input;
    while(true)
    {
        std::cout << "Enter Phone Number: ";
        if(!getline(std::cin, input))
        {
            if(std::cin.eof())
            {
                std::cout << "Exited\n";
                exit(1);
            }
            std::cout << "Try Again!\n";
        }
        else if(input.empty() || !isNumber(input) || input.length() != 10)
            std::cout << "Try Again!\n";
        else
        {
            newContact->setPhoneNumber(input);
            break ;
        }
    }
}

void    addSecret(Contact *newContact)
{
    std::string input;
    while(true)
    {
        std::cout << "Enter Darkest Secret: ";
        if(!getline(std::cin, input))
        {
            if(std::cin.eof())
            {
                std::cout << "Exited\n";
                exit(1);
            }
            std::cout << "Try Again!\n";
        }
        else if(input.empty() || !isValid(input))
            std::cout << "Try Again!\n";
        else
        {
            newContact->setDarkestSecret(input);
            break ;
        }
    }
}

void    PhoneBook::add()
{
    Contact newContact;

    addFirstName(&newContact);
    addLastName(&newContact);
    addNickName(&newContact);
    addPhoneNumber(&newContact);
    addSecret(&newContact);
    contacts[contactIndex % 8] = newContact;
    contactIndex++;  
    std::cout << "CONTACT ADDED !\n";

}

void    PhoneBook::search()
{
    int limit = contactIndex;
    int index;
    std::string input;

    if(!contactIndex)
    {
        std::cout << "Phonebook Is Empty!\n";
        return ;
    }
    std::cout   << std::setw(10) << "Index" << "|" 
                << std::setw(10) << "First Name" << "|" 
                << std::setw(10) << "Last Name" << "|" 
                << std::setw(10) << "Nick Name" << std::endl;
            
    if(contactIndex > 8)
        limit = 8;
    for(int i = 0; i < limit; i++)
    {
        std::cout   << std::setw(10) << i << "|" 
                    << std::setw(10) << truncate(contacts[i].getFirstName()) << "|"
                    << std::setw(10) << truncate(contacts[i].getLastName()) << "|"
                    << std::setw(10) << truncate(contacts[i].getNickName()) << std::endl;
    }
    while(true)
    {
        
        std::cout << "Enter desired index: ";
        if(!getline(std::cin, input))
        {
            if(std::cin.eof())
            {
                std::cout << "\nExited!\n";
                exit(1);
            }
            std::cout << "NOT VALID!\n";
        }
        std::stringstream ss(input);
        ss >> index;
        if((input.empty() || !isNumber(input)) || (index < 0 || index >= limit))
            std::cout << "NOT VALID!\n" << "Enter an index in this range: 0 - " << limit - 1 << std::endl ;
        else
            break ;
    }
    printContact(index);
}

void    PhoneBook::printContact(int index)
{
    std::cout   << "First Name    : " << contacts[index].getFirstName()
                << "\nLast Name     : " << contacts[index].getLastName()
                << "\nNick Name     : " << contacts[index].getNickName()
                << "\nPhone Number  : " << contacts[index].getPhoneNumber()
                << "\nDarkest Secret: " << contacts[index].getDarkestSecret() << std::endl;

}
