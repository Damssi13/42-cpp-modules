#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP


#include <iostream>

class ClapTrap{
private:
    std::string name;
    unsigned int hitPoint;
    unsigned int energyPoint;
    unsigned int attackDamage;

public:
    ClapTrap();
    ClapTrap(const std::string &newName);
    ClapTrap(const ClapTrap &other);
    ClapTrap    &operator= (const ClapTrap &other);
    ~ClapTrap();

    void    printInfo();
    void    attack(const std::string &target);
    void    beRepaired(unsigned int amount);
    void    takeDamage(unsigned int amount);

};

#endif