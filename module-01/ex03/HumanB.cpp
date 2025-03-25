#include "HumanB.hpp"

HumanB::HumanB(std::string newName)
{
    name = newName;
    weapon = NULL;
    if(newName.empty())
        name = "Unknown";
}

void    HumanB::attack()
{
    if(weapon)
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
    else
        std::cout << name << " does not have a weapon" << std::endl;

}

void    HumanB::setWeapon(Weapon &newWeapon)
{
    weapon = &newWeapon;
}