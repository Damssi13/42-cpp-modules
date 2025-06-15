#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
    (void)other;
    *this = other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter(){}

void    ScalarConverter::convert(const std::string& literal)
{
    if(literal.empty())
    {
        std::cerr << "Error: Empty input\n";
        return ;
    }

    if(isChar(literal))
        charConverter(literal);
    else if(isInt(literal))
        intConverter(literal);
    else if(isFloat(literal))
        floatConverter(literal);
    else if(isDouble(literal))
        doubleConverter(literal);


}

//////////////////////////////////////////////////
//               IS FUNCTIONS  
bool    ScalarConverter::isChar(const std::string& literal){
    return(literal.length() == 1 && !std::isdigit(literal[0]));
}

bool    ScalarConverter::isInt(const std::string& literal){
    char *ptr;

    strtol(literal.c_str(), &ptr, 10);
    return(*ptr == '\0' && literal.find(".") == std::string::npos);
}

bool    ScalarConverter::isFloat(const std::string& literal){
    char *ptr;

    if(literal == "nanf" || literal == "+inff" || literal == "-inff")
        return true;
    strtof(literal.c_str(), &ptr);
    return(*ptr == 'f' && *(ptr + 1) == '\0');
}

bool    ScalarConverter::isDouble(const std::string& literal){
    char *ptr;
    
    if(literal == "nan" || literal == "+inf" || literal == "-inf")
    return true;
    strtof(literal.c_str(), &ptr);
    return(*ptr == '\0');
}

//////////////////////////////////////////////////

void    ScalarConverter::charConverter(const std::string& literal){
    char c = literal[0];

    printChar(c);
    printInt(static_cast<int>(c));
    printFloat(static_cast<float>(c));
    printDouble(static_cast<double>(c));
    
}

void    ScalarConverter::intConverter(const std::string& literal){
    long value = strtol(literal.c_str(), NULL, 10);

    if(value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max() )
    {
        std::cout << "char: impossible\n" << "int: impossible\n"
                  << "float: impossible\n" << "double: impossible\n";
    }

    printChar(static_cast<char>(value));
    printInt(static_cast<int>(value));
    printFloat(static_cast<float>(value));
    printDouble(static_cast<double>(value));
}

void    ScalarConverter::floatConverter(const std::string& literal){
    float value;

    if(literal == "nanf" || literal == "+inff" || literal == "-inff")
    {
        if(literal == "nanf")
            value = std::numeric_limits<float>::quiet_NaN();
        else if(literal == "+inff")
            value = std::numeric_limits<float>::infinity();
        else if(literal == "-inff")
            value = -std::numeric_limits<float>::infinity();
    }
    else
        value = strtof(literal.c_str(), NULL);

    if(std::isnan(value) || std::isinf(value))
        std::cout << "char: impossible\n";
    else
        printChar(static_cast<char>(value));

    if(std::isnan(value) || std::isinf(value))
        std::cout << "int: impossible\n";
    else
        printInt(static_cast<int>(value));

    printFloat(value);
    printDouble(value);
}

void    ScalarConverter::doubleConverter(const std::string& literal){
    double value;

    if(literal == "nan" || literal == "+inf" || literal == "-inf")
    {
        if(literal == "nan")
            value = std::numeric_limits<double>::quiet_NaN();
        else if(literal == "+inf")
            value = std::numeric_limits<double>::infinity();
        else if(literal == "-inf")
            value = -std::numeric_limits<double>::infinity();
    }
    else
        value = strtof(literal.c_str(), NULL);

    if(std::isnan(value) || std::isinf(value))
        std::cout << "char: impossible\n";
    else
        printChar(static_cast<char>(value));

    if(std::isnan(value) || std::isinf(value))
        std::cout << "int: impossible\n";
    else
        printInt(static_cast<int>(value));

    printFloat(value);
    printDouble(value);
}

///////////////////////////////////
//PRINT FUNCTIONS

void    ScalarConverter::printChar(char value)
{
    std::cout << "char: ";
    if(std::isprint(value))
        std::cout << "'" << value << "'\n";
    else
        std::cout << "Non displayable\n";
}

void    ScalarConverter::printInt(int value)
{
    std::cout << "int: " << value << std::endl;
}

void    ScalarConverter::printFloat(float value)
{
    std::cout << "float: " << value;
    if(value == static_cast<int>(value))
        std::cout << ".0";
    std::cout << "f\n";
}


void    ScalarConverter::printDouble(double value)
{
    std::cout << "double: " << value;
    if(value == static_cast<int>(value))
        std::cout << ".0";
    std::cout << std::endl;
}