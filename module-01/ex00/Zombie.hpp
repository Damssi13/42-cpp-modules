#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie{
private:
    std::string name;
public:
    Zombie();
    void        announce();
    void        randomChump(std::string name);
    void        setName(std::string newName);
    std::string getName();
    ~Zombie();
};

#endif