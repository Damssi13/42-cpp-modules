#include "Brain.hpp"

Brain::Brain()
{
    for(int i = 0; i < 100; i++)
        ideas[i] = "Empty";

    std::cout << "Brain Default Constructor called!\n";
}

Brain::Brain(const Brain &other)
{
    for(int i = 0; i < 100; i++)
        ideas[i] = other.ideas[i];
    
    std::cout << "Brain Copy constructor called\n";
}

Brain   &Brain::operator=(const Brain &other)
{
    
    if(this != &other)
    {
        for(int i = 0; i < 100; i++)
            ideas[i] = other.ideas[i];
    }
    return *this;
}

Brain::~Brain()
{
    std::cout << "Brain Destructor called!\n";
}

void    Brain::setIdea(int index, std::string idea)
{
    if(index > 100 || index < 0)
        return ;
    ideas[index] = idea;
}

std::string     Brain::getIdea(int index)
{
    if(index > 100 || index < 0)
        return "Invalid";
    return ideas[index];
}