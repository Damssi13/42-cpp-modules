#include "Fixed.hpp"


Fixed::Fixed() : value(0)
{
    // std::cout << "Default constructor called !\n";
} 

Fixed::Fixed(const Fixed &other)
{
    // std::cout << "Copy constructor called !\n";
    *this = other;
}

Fixed::Fixed(const int intNum)
{
    value = intNum << fractionalBits;
    // std::cout << "Int constructor called!\n";
}

Fixed::Fixed(const float floatNum) 
{
    value = roundf(floatNum * (1 << fractionalBits));
    // std::cout << "Float constructor called!\n";
}

Fixed   &Fixed::operator=(const Fixed &fixed)
{
    if(&fixed != this)
        value = fixed.value;
    return *this;
}

int     Fixed::getRawBits() const
{
    return value;
}

void    Fixed::setRawBits(int const raw)
{
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

/*____ Comparision Operatros ____*/
bool    Fixed::operator<(const Fixed &fixed) const
{
    return value < fixed.value;
}

bool    Fixed::operator>(const Fixed &fixed) const
{
    return value > fixed.value;
}

bool    Fixed::operator<=(const Fixed &fixed)const
{
    return value <= fixed.value;
}

bool    Fixed::operator>=(const Fixed &fixed)const
{
    return value >= fixed.value;
}

bool    Fixed::operator==(const Fixed &fixed)const
{
    return value == fixed.value;
}

bool    Fixed::operator!=(const Fixed &fixed)const
{
    return value != fixed.value;
}


/*____ Arthemtic Operators ____*/
Fixed   Fixed::operator+(const Fixed &fixed)const
{
    return Fixed(toFloat() + fixed.toFloat());
}

Fixed   Fixed::operator-(const Fixed &fixed)const
{
    return Fixed(toFloat() - fixed.toFloat());
}

Fixed   Fixed::operator*(const Fixed &fixed)const
{
    return Fixed(toFloat() * fixed.toFloat());
}

Fixed   Fixed::operator/(const Fixed &fixed)const
{
    return Fixed(toFloat() / fixed.toFloat());
}


/*____ Increment and Decrement Operators ____*/
Fixed   &Fixed::operator++()
{
    value++;
    return *this;
}

Fixed   &Fixed::operator--()
{
    value--;
    return *this;
}

Fixed   Fixed::operator++(int)
{
    Fixed temp = *this;
    value++;
    return temp;
}

Fixed   Fixed::operator--(int)
{
    Fixed temp = *this;
    value--;
    return temp;
}

/*____ Min and Max ____*/

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return a > b ? a : b;
}

Fixed   &Fixed::max(Fixed &a, Fixed &b)
{
    return a > b ? a : b;
}

const Fixed   &Fixed::min(const Fixed &a, const Fixed &b)
{
    return a < b ? a : b;
}

Fixed   &Fixed::min(Fixed &a, Fixed &b)
{
    return a < b ? a : b;
}

Fixed::~Fixed()
{
    // std::cout << "Destructor Called!\n";
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
    os << fixed.toFloat();
    return os;
}