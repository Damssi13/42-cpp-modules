#include "Fixed.hpp"


Fixed::Fixed() : value(0)
{
    std::cout << "Default constructor called !\n";
} 

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called !\n";
    *this = other;
}

Fixed::Fixed(const int intNum)
{
    value = intNum << fractionalBits;
    std::cout << "Int constructor called!\n";
}

Fixed::Fixed(const float floatNum) 
{
    value = roundf(floatNum * (1 << fractionalBits));
    std::cout << "Float constructor called!\n";
}

Fixed   &Fixed::operator=(const Fixed &fixed)
{
    std::cout << "Copy assignment called !\n";
    if(&fixed != this)
    {
        value = fixed.value;
    }
    return *this;
}

int     Fixed::getRawBits() const
{
    std::cout << "getRawBits function called!\n";
    return value;
}

void    Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits function called!\n";
    value = raw;
}

float   Fixed::toFloat() const
{
    return (float)value / (1 << fractionalBits);
}

int     Fixed::toInt() const
{
    return value >> fractionalBits;
}


Fixed::~Fixed()
{
    std::cout << "Destructor Called!\n";
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
    os << fixed.toFloat();
    return os;
}