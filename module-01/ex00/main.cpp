#include "Zombie.hpp"


int main()
{
    Zombie *rachid; 
    Zombie doo("doooo!");
    
    doo.announce();
    rachid = newZombie("rachid");
    randomChump("randomChumpanzie");
    rachid->announce();
    delete rachid;

}