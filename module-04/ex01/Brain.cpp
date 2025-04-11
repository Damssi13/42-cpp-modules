#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain Default Constructor called!\n";
}

Brain::Brain(const Brain &other)
{
    std::cout << "Brain Copy constructor called\n";
}

Brain   &Brain::operator=(const Brain &other)
{
    if(this != &other)
    {
        this->ideas = other.ideas;
    }
    return *this;
}

Brain::~Brain()
{
    std::cout << "Brain Destructor called!\n";
}