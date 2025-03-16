#include "Zombie.hpp"

int main()
{
    Zombie *lfrg;

    lfrg = zombieHorde(20, "carlos");
    if(lfrg == NULL)
    {
        std::cout << "Found an error\n";
        return 0;
    }
    for(int i = 0; i < 20 ; i++)
    {
        lfrg[i].announce();
    }
    delete[] lfrg;
}