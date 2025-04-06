#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Unknown"), hitPoint(10), energyPoint(10), attackDamage(0)
{
    std::cout << "ClapTrap Default constructor called!\n";
}

//when deleting Const the main can not accept the string reference. WHY
ClapTrap::ClapTrap(const std::string &Newname) : hitPoint(10), energyPoint(10), attackDamage(0)
{
    name = Newname;
    std::cout << name <<" ClapTrap Parameterized constructor called!\n";
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    std::cout << "Copy constructor called\n";
    *this = other;    
}

ClapTrap    &ClapTrap::operator=(const ClapTrap &other)
{
    std::cout << "ClapTrap Copy assignment called\n";
    if(this != &other)
    {
        this->name = name;
        this->hitPoint = hitPoint;
        this->energyPoint = energyPoint;
        this->attackDamage = attackDamage;
    }
    return *this;
}

 //no energy/hit points = nothing //  all good =  Print message, energy--
void    ClapTrap::attack(const std::string &target)
{
    if(energyPoint == 0 || hitPoint == 0)
    {
        std::cout << "ClapTrap " << name << " cannot Attack because No Energy/Hit points left\n";
        return ;
    }
    std::cout << "ClapTrap " << name << " attacks " << target << " causing " << attackDamage << " points of damage!\n";
    energyPoint--;
}


// negative value = Error // //no energy/hit points = nothing //  all good =  Print message, energy--
void    ClapTrap::takeDamage(unsigned int amount)
{
    if((int)amount <= 0 || amount > 10)
    {
        std::cerr << "Values not allowed\n";
        return ;
    }
    else if(hitPoint == 0)
    {
        std::cout << "ClapTrap " << name << " cannot take damage, it is already dead\n";
        return ;
    }
    amount > hitPoint? hitPoint = 0 : hitPoint -= amount;
    std::cout << "ClapTrap " << name << " took " << amount << " points of damage!\n";
}

// negative value = Error // //no energy/hit points = nothing //  all good =  Print message, add the HP, energy--
void    ClapTrap::beRepaired(unsigned int amount)
{
    if((int)amount <= 0 || amount > 10 )
    {
        std::cerr << "Values not allowed\n";
        return ;
    }
    else if(energyPoint == 0 || hitPoint == 0)
    {
        std::cout << "ClapTrap " << name << " cannot Repair because No Energy/Hit points left\n";
        return ;
    }
    std::cout << "ClapTrap " << name << " repaired " << amount << " points of damage!\n";
    hitPoint += amount;
    energyPoint--;
}

void    ClapTrap::printInfo()
{
    std::cout   << "______________________\n"
                << "Name = " << name << std::endl
                << "HP = " << hitPoint << std::endl
                << "Energy = " << energyPoint << std::endl
                << "Attak Damage = " << attackDamage << std::endl
                << "______________________\n"; 
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap Destructor called!\n";
}