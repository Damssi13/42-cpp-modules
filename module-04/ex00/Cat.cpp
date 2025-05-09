#include "Cat.hpp"

Cat::Cat() 
{
    type = "Cat";
    std::cout << "Cat Default Constructor called!\n";
}

Cat::Cat(const Cat &other) : Animal(other)
{
    std::cout << "Cat Copy Constructor called!\n";
    *this = other;
}

Cat     &Cat::operator=(const Cat &other)
{
    if(this != &other)
    {
        type = other.type;
    }
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat Destructor called!\n";
}

void    Cat::makeSound() const
{
    std::cout << "Meow !\n";
}
