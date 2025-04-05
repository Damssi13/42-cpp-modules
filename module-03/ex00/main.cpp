#include "ClapTrap.hpp"

int main()
{
    ClapTrap a("luffy");
    ClapTrap b("Goku");


    b.attack("Friza");
    b.takeDamage(6);
    
    a.attack("Crocodile");
    a.takeDamage(8);
    a.beRepaired(3);

    b.beRepaired(2);
    b.attack("Friza");
    b.attack("Friza");
    b.attack("Friza");
    b.attack("Friza");
    b.attack("Friza");
    b.takeDamage(8);
    b.beRepaired(3);
    b.beRepaired(3);
    b.attack("Friza");
    b.attack("Friza");


    b.printInfo();


    std::cout << "_______________________________\n";


}