#include "ClapTrap.hpp"

int main()
{
    ClapTrap obj("Naruto");

    obj.printInfo();
    obj.takeDamage(3);
    obj.takeDamage(3);
    obj.takeDamage(-5);
    obj.printInfo();

}