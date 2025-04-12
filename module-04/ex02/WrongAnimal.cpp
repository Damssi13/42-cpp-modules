#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    type = "WrongAnimal";
    std::cout << "WrongAnimal Default constructor called!\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) 
{
    std::cout << "WrongAnimal Copy constructor called!\n";
    *this = other;
}

WrongAnimal  &WrongAnimal::operator= (const WrongAnimal &other)
{
    if (this != &other)
    {
        type = other.type;
    }
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal Destructor called!\n";
}


std::string WrongAnimal::getType() const
{
    return type;
}

void    WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal sound!\n";
}