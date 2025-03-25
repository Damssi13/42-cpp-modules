#include "Zombie.hpp"



Zombie::Zombie(std::string newName)
{
    name = newName;
}

void    Zombie::announce()
{
    std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}

Zombie::~Zombie()
{
    std::cout<< "The destructor for: " << name << std::endl;
}