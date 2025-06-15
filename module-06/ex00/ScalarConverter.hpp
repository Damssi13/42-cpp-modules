#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP 


#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
#include <cstdlib>
#include <limits>

class ScalarConverter{
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter& other);
    ScalarConverter& operator= (const ScalarConverter& other);
    ~ScalarConverter();

public:
    static void    convert(const std::string& literal);

    static bool     isChar(const std::string& literal);
    static bool     isInt(const std::string& literal);
    static bool     isFloat(const std::string& literal);
    static bool     isDouble(const std::string& literal);
    
    
    static void    charConverter(const std::string& literal);
    static void    intConverter(const std::string& literal);
    static void    floatConverter(const std::string& literal);
    static void    doubleConverter(const std::string& literal);
    
    static void     printChar(char value);
    static void     printInt(int value);
    static void     printFloat(float value);
    static void     printDouble(double value);
};


#endif