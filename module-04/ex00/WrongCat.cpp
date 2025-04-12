#include "WrongCat.hpp"

WrongCat::WrongCat() 
{
    type = "WrongCat";
    std::cout << "WrongCat Defualt Constructor called!\n";
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
    std::cout << "WrongCat Copy Constructor called!\n";
    *this = other;
}

WrongCat     &WrongCat::operator=(const WrongCat &other)
{
    if(this != &other)
    {
        type = other.type;
    }
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat Destructor called!\n";
}

void    WrongCat::makeSound() const
{
    std::cout << "Wrong Meow !\n";
}
