#include "Dog.hpp"

Dog::Dog()
{
    type = "Dog";
    brain = new Brain;
    std::cout << "Dog Default Constructor called!\n";
}

Dog::Dog(const Dog &other) : Animal(other)
{
    brain = new Brain(*other.brain);
    std::cout << "Dog Copy Constructor called!\n";
    *this = other;
}

Dog     &Dog::operator=(const Dog &other)
{
    if(this != &other)
    {
        delete brain;
        brain = new Brain(*other.brain);
        type = other.type;
    }
    return *this;
}

Brain   *Dog::getBrain() const
{
    return brain;
}

void    Dog::makeSound() const
{
    std::cout << "Woof !\n";
}

Dog::~Dog()
{
    delete brain;
    std::cout << "Dog Destructor called!\n";
}

