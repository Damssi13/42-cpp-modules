#include "Zombie.hpp"

int main()
{
    Zombie *lfrg;

    lfrg = zombieHorde(3, "rachidos");
    if(lfrg == NULL)
    {
        std::cout << "Found an error\n";
        return 0;
    }
    for(int i = 0; i < 3 ; i++)
    {
        lfrg[i].announce();
    }
    delete[] lfrg;
}