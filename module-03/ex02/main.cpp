#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"


int main()
{
    ClapTrap clap;
    clap = ClapTrap("newjersy");
    // std::cout << std::endl;
    // clap = FragTrap("Jiri");
    // std::cout << std::endl;
    // ScavTrap scav;
    // std::cout << std::endl;
    // FragTrap frag;
    // std::cout << std::endl;
    clap.attack("nani");
}