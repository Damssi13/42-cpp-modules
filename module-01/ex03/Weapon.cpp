#include "Weapon.hpp"

Weapon::Weapon(std::string newType)
{
    type = newType;
    if(newType.empty())
        type = "Hidden Weapon";
}

void    Weapon::setType(std::string newType)
{
    type = newType;
}

const std::string     &Weapon::getType()
{
    return type;
}