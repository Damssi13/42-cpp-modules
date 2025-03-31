#include "Fixed.hpp"

Fixed::Fixed() : value(0)
{
    std::cout << "Default constructor called!\n";
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called!\n";
    *this = other;
}

Fixed    &Fixed::operator=(const Fixed &fixed)
{
    std::cout << "Copy assignment called!\n";
    if(this != &fixed)
        value = fixed.getRawBits();
    return *this;
}

int     Fixed::getRawBits() const
{
    std::cout << "getRawBits function called!\n";
    return value;
}

void    Fixed::setRawBits(int const raw)
{
    value = raw;
}
Fixed::~Fixed()
{
    std::cout << "Destructor Called!\n";
}