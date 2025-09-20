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
    void            validValue(std::string& value);//should be bool
    bool            validDate(const std::string& date);

};

std::string trim(const std::string& data);
bool isDigits(const std::string& number);
