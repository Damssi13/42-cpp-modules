#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed{
private:
    int value;
    static const int fractionalBits = 8;
public:
    Fixed();
    Fixed(const int intNum);
    Fixed(const float floatNum);
    Fixed(const Fixed &other);
    Fixed   &operator= (const Fixed &fixed);
    ~Fixed();
    
    int     getRawBits() const;
    void    setRawBits(int const raw);
    float   toFloat() const;
    int     toInt() const;
};

std::ostream   &operator<<(std::ostream &os, const Fixed &fixed);

#endif