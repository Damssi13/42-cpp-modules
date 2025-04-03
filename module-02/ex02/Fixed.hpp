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

    bool    operator>(const Fixed &fixed) const;
    bool    operator<(const Fixed &fixed) const;
    bool    operator>=(const Fixed &fixed) const;
    bool    operator<=(const Fixed &fixed) const;
    bool    operator==(const Fixed &fixed) const;
    bool    operator!=(const Fixed &fixed) const;

    Fixed   operator+(const Fixed &fixed) const;
    Fixed   operator-(const Fixed &fixed) const;
    Fixed   operator*(const Fixed &fixed) const;
    Fixed   operator/(const Fixed &fixed) const;

    Fixed   &operator++();
    Fixed   operator++(int num);
    Fixed   &operator--();
    Fixed   operator--(int num);
    
    static Fixed &min(Fixed &a, Fixed &b);
    static const Fixed &min(const Fixed &a, const Fixed &b);
    static Fixed &max(Fixed &a, Fixed &b);
    static const Fixed &max(const Fixed &a, const Fixed &b);

    int     getRawBits() const;
    void    setRawBits(int const raw);
    float   toFloat() const;
    int     toInt() const;
    
};

std::ostream   &operator<<(std::ostream &os, const Fixed &fixed);

#endif