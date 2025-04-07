#include "FragTrap.hpp"

FragTrap::FragTrap() 
{
    this->hitPoint = 100;
    this->energyPoint = 100;
    this->attackDamage = 30;
    std::cout << "FragTrap Default constructor called!\n";
}

//when deleting Const the main can not accept the string reference. WHY
FragTrap::FragTrap(const std::string &newName) : ClapTrap(newName)
{
    this->hitPoint = 100;
    this->energyPoint = 100;
    this->attackDamage = 30;
    std::cout << newName <<" FragTrap Parameterized constructor called!\n";
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
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
    std::cout << name <<" requests a high five!\n";
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap Destructor called!\n";
}