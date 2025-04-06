#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    this->hitPoint = 100;
    this->energyPoint = 50;
    this->attackDamage = 20;
    std::cout << "FragTrap Default constructor called!\n";
}

//when deleting Const the main can not accept the string reference. WHY
FragTrap::FragTrap(const std::string &Newname) : ClapTrap(Newname)
{
    this->hitPoint = 100;
    this->energyPoint = 50;
    this->attackDamage = 20;
    std::cout << Newname <<" FragTrap Parameterized constructor called!\n";
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap()
{
    std::cout << "FragTrap Copy constructor called\n";
    *this = other;    
}

FragTrap    &FragTrap::operator=(const FragTrap &other)
{
    std::cout << "FragTrap Copy assignment called\n";
    if(this != &other)
    {
        this->name = name;
        this->hitPoint = hitPoint;
        this->energyPoint = energyPoint;
        this->attackDamage = attackDamage;
    }
    return *this;
}


void    FragTrap::highFiveGuys()
{
    std::cout << "HIGH FIVE GUUUYS!\n";
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap Destructor called!\n";
}