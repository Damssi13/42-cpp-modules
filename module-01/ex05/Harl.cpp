#include "Harl.hpp"


void    Harl::debug()
{
    std::cout << "I love having extra chicken for my 7XL-double-cheese-triple-pickle-special ketchup burger. I really do!\n";
}

void    Harl::info()
{
    std::cout << "I cannot believe adding extra chicken costs more money. You did not put enough chicken in my burger! If you did, I wouldn't be asking for more!\n";
}

void    Harl::warning()
{
    std::cout << "I think I deserve to have some extra chicken for free. I've been coming for years whereas you started working here since last month.\n";
}

void    Harl::error()
{
    std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}

void    Harl::complain(std::string level)
{
    void (Harl::*funcPtr[4])() = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error,
    };

    std::string levels[4] = {
        "DEBUG",
        "INFO",
        "WARNING",
        "ERROR",
    };
    for(int i = 0; i < 4; i++)
    {
        if(levels[i] == level)
        {
            (this->*funcPtr[i])();
            return ;
        }
    }
    std::cout << "Unkown Level\n";

}