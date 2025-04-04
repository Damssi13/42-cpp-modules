#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Unknown"), hitPoint(10), energyPoint(10), attackDamage(0)
{
    std::cout << "Default constructor called!\n";
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    std::cout << "Copy constructor called\n";
    *this = other;    
}

ClapTrap    &ClapTrap::operator=(const ClapTrap &other)
{
    std::cout << "Copy assignment called\n";
    if(this != &other)
    {
        this->name = name;
        this->hitPoint = hitPoint;
        this->energyPoint = energyPoint;
        this->attackDamage = attackDamage;
    }
    return *this;
}


void    ClapTrap::attack(const std::string &target)
{
    std::cout << "ClapTrap " << name << " attacks " << target << " causing " <<attackDamage << " points of damage!\n";
    energyPoint--;
    attackDamage--;
}

void    ClapTrap::takeDamage(unsigned amount)
{
    hitPoint -= amount;
    std::cout << "ClapTrap took Damage\n";
}

void    ClapTrap::beRepaired(unsigned amount)
{
    std::cout << "ClapTrap Repaired\n";
    hitPoint += amount;
    energyPoint--;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called!\n";
}