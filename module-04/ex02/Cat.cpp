#include "Cat.hpp"

Cat::Cat() 
{
    type = "Cat";
    brain = new Brain;
    std::cout << "Cat Default Constructor called!\n";
}

Cat::Cat(const Cat &other) : Animal(other)
{
    brain = new Brain(*other.brain);
    std::cout << "Cat Copy Constructor called!\n";
    *this = other;
}

Cat     &Cat::operator=(const Cat &other)
{
    if(this != &other)
    {
        delete brain;
        brain = new Brain(*other.brain);
        type = other.type;
    }
    return *this;
}

Cat::~Cat()
{
    delete brain;
    std::cout << "Cat Destructor called!\n";
}

void    Cat::makeSound() const
{

    std::cout << "Meow !\n";
}

Brain   *Cat::getBrain() const
{
    return brain;
}