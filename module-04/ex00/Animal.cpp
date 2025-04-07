#include "Animal.hpp"


Animal::Animal() : type(type)
{
    std::cout << "Animal Default constructor called!\n";
}

Animal::Animal(const Animal &other)
{
    std::cout << "Animal Copy constructor called!\n";
    *this = other;
}

Animal  &Animal::operator= (const Animal &other)
{
    if (this != &other)
    {
        type = other.type;
    }
    return *this;
}

Animal::~Animal()
{
    std::cout << "Animal Destructor called!\n";
}

void    Animal::setType(std::string type)
{
    this->type = type;
}

std::string Animal::getType()
{
    return type;
}