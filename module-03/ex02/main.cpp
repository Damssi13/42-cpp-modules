#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"


int main()
{
    ScavTrap scav1;
    ScavTrap scav("Rachid");
    std::cout << "_______________________________\n";
    ClapTrap clap("Anas");
    std::cout << "_______________________________\n";
    FragTrap frag("Hamza");
    std::cout << "_______________________________\n";
    frag.attack("Jifra");

    // scav.printInfo();
    // scav.printad();
    scav.guardGate();

}