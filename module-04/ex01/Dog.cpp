#include "Dog.hpp"

Dog::Dog()
{
    type = "Dog";
    brain = new Brain;
    std::cout << "Dog Default Constructor called!\n";
}

Dog::Dog(const Dog &other) : Animal(other)
{
    std::cout << "Dog Copy Constructor called!\n";
    *this = other;
}

Dog     &Dog::operator=(const Dog &other)
{
    if(this != &other)
    {
        type = other.type;
    }
    return *this;
}

Dog::~Dog()
{
    delete brain;
    std::cout << "Dog Destructor called!\n";
}

void    Dog::makeSound() const
{
    std::cout << "Woof !\n";
}
