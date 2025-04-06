#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ScavTrap scav("Rachid");
    ClapTrap clap("Anas");



    clap.printInfo();
    scav.printInfo();
    clap.beRepaired(4);
    // scav.printInfo();
    // scav.printad();
    std::cout << "_______________________________\n";
    scav.guardGate();

}