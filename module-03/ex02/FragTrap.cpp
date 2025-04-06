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
        this->name = other.name;
        this->hitPoint = other.hitPoint;
        this->energyPoint = other.energyPoint;
        this->attackDamage = other.attackDamage;
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