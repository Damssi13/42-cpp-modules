#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP


#include <iostream>

class ClapTrap{
private:
    std::string name;
    int hitPoint;
    int energyPoint;
    int attackDamage;

public:
    ClapTrap();
    ClapTrap(const ClapTrap &other);
    ClapTrap    &operator= (const ClapTrap &other);
    ~ClapTrap();


    void    ClapTrap::attack(const std::string &target);
    void    ClapTrap::beRepaired(unsigned amount);
    void    ClapTrap::takeDamage(unsigned amount);

};

#endif