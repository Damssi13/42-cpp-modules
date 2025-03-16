#include "Zombie.hpp"


Zombie *zombieHorde(int N, std::string name)
{
    if(N <= 0)
    {
        std::cerr << "The number of zombies is not Valid!\n";
        return NULL;
    }
    Zombie *horde = new Zombie[N];
    for(int i = 0; i < N; i++)
    {
        horde[i].setName(name);
    }
    return horde;
}