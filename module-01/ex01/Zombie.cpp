#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::Zombie(std::string newName)
{
    name = newName;
}

void    Zombie::announce()
{
    std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}

void    Zombie::setName(std::string newName)
{
    name = newName;
}

Zombie::~Zombie()
{
    std::cout<< "The destructor for: " << name << std::endl;
}

