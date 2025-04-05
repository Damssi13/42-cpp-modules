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


    void    attack(const std::string &target);
    void    beRepaired(unsigned amount);
    void    takeDamage(unsigned amount);

};

#endif