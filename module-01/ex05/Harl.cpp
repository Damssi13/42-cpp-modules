#include "Harl.hpp"


void    Harl::debug()
{
    std::cout << "I love having extra chicken for my 7XL-double-cheese-triple-pickle-specialketchup burger.\nI really do!\n";
}

void    Harl::info()
{
    std::cout << "I cannot believe adding extra chicken costs more money.\nYou did not put enough chicken in my burger! If you did, I wouldn't be asking for more!";
}

void    Harl::warning()
{
    std::cout << "I think I deserve to have some extra chicken for free.\nI've been coming for years whereas you started working here since last month.\n";
}

void    Harl::error()
{
    std::cout << "This is unacceptable! I want to speak to the manager now.";
}

void    Harl::complain(std::string level)
{
    void (Harl::*levels[4])() = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error,
    };

    

}