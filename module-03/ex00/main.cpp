#include "ClapTrap.hpp"

int main()
{
    ClapTrap two("Rachid");
    ClapTrap one("ayoub");

    ClapTrap three;

    three = two;
    three.attack("Enemy");
    three.takeDamage(145);
    one.printInfo();
    std::cout << "_______________________________\n";
}