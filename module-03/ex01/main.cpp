#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ClapTrap clap("Rachid");
    ScavTrap scav("Ayoub");
    
    clap.attack("Enemy");
    clap.takeDamage(5);
    clap.beRepaired(4);
    
    scav.attack("Enemy");
    scav.takeDamage(5);
    scav.beRepaired(4);
    
}