#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal{
protected:
    std::string type;

public:
    Animal();
    Animal(const Animal &other);
    Animal  &operator=(const Animal &other);
    ~Animal();

    void            makeSound();
    void            setType(std::string type);
    std::string     getType();
};


#endif