#pragma once


#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <map>

class BitcoinExchange{
private:
    std::string _strs;
    std::map<std::string, float> _table; 

public:

    BitcoinExchange();
    BitcoinExchange(const std::string& file);
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();

    void            parse(const std::string& file);
    std::string     parseLine(std::string& line);
    bool            validValue(std::string& value);
    bool            validDate(const std::string& date);
    bool            isDigit(const std::string& str);

};

std::string trim(std::string& data);