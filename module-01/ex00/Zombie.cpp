#include "Zombie.hpp"


Zombie::Zombie() {}

void    Zombie::announce()
{
    std::cout << name << "BraiiiiiiinnnzzzZ...\n";
}

Zombie::~Zombie()
{
    std::cout<< "The destructor for " << getName() << std::endl;
}

void    Zombie::setName(std::string newName)
{
    name = newName;
}
std::string    Zombie::getName()
{
    return name;
}

void    randomChump(std::string name)
{
    Zombie newZombie;
    newZombie.setName(name);
    newZombie.announce();
}

Zombie *newZombie(std::string name)
{
    Zombie *newZombie = new(sizeof(*Zombie));
    newZombie->setName(name);
    return newZombie;
}