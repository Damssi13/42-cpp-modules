#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    this->hitPoint = 100;
    this->energyPoint = 50;
    this->attackDamage = 20;
    std::cout << "ScavTrap Default constructor called!\n";
}

//when deleting Const the main can not accept the string reference. WHY
ScavTrap::ScavTrap(const std::string &newName) : ClapTrap(newName)
{
    this->hitPoint = 100;
    this->energyPoint = 50;
    this->attackDamage = 20;
    std::cout << newName <<" ScavTrap Parameterized constructor called!\n";
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
    std::cout << "ScavTrap Copy constructor called\n";
    *this = other;    
}

ScavTrap    &ScavTrap::operator=(const ScavTrap &other)
{
    std::cout << "ScavTrap Copy assignment called\n";
    if(this != &other)
    {
        this->name = other.name;
        this->hitPoint = other.hitPoint;
        this->energyPoint = other.energyPoint;
        this->attackDamage = other.attackDamage;
    }
    return *this;
}

 //no energy/hit points = nothing //  all good =  Print message, energy--
void    ScavTrap::attack(const std::string &target)
{
    if(energyPoint == 0 || hitPoint == 0)
    {
        std::cout << "ScavTrap " << name << " cannot Attack because No Energy/Hit points left\n";
        return ;
    }
    std::cout << "ScavTrap " << name << " attacks " << target << " causing " << attackDamage << " points of damage!\n";
    energyPoint--;
}


void    ScavTrap::guardGate()
{
    std::cout << "ScavTrap is now in Gate keeper mode\n";
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Destructor called!\n";
}