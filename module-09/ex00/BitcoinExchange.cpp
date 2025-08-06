#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string& file)
{
    (void)file;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {(void)other;}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    // if(this != &other)
    (void)other;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}


void    BitcoinExchange::parse(const std::string& file)
{
    int lines = 0;
    std::string line;
    std::ifstream filein(file.c_str());
    if(!filein.is_open())
        throw std::runtime_error("Could not open the file");

    while(std::getline(filein, line))
    {
        std::cout << ++lines << std::endl;
        _strs += parseLine(line) + "\n";
    }

    std::cout << _strs << std::endl;
    filein.close();
    exit(1);







    // int pos = 0;
    // if(_strs.find("|") == std::string::npos)
    //     throw 
    // while(_strs[pos])
    // {
    //     while(_strs[pos] != '\n')
    //     {   
    //         if(_strs[pos])
    //     }
    // }
}

std::string    BitcoinExchange::parseLine(std::string& line)
{
    size_t pipe;
    double num;
    pipe =  line.find("|");
    if(pipe == std::string::npos)
        return "Unvalid format.";
    
    std::string date;
    std::string value;

    date = line.substr(0, pipe);
    value = line.substr(pipe + 1);
    std::stringstream ss(value);
    ss >> num;

    if(num > 1000)
        return "Error: too large number.";
    else if(num < 0 || isDigit(value))
        return "Error: not a positive number.";


    if(!validDate(date))

    date = trim(date);
    value = trim(value);
    return date + "|" + value;

}

bool BitcoinExchange::isDigit(const std::string &str)
{

    for (size_t i = 0; i < str.size(); i++)
    {
        if (!isdigit(str[i]))
            return false;
    }
    return true;
}

//   too large number
//   not a positive number
//   bad input -> 

bool BitcoinExchange::validDate(const std::string& date)
{
    size_t first;
    first = date.find("-");
    std::string year = date.substr(0, first);


}


// bool BitcoinExchange::validValue(const std::string& value)
// {
    
// }

std::string trim(std::string& data)
{
    size_t first = 0;
    while (first < data.size() && std::isspace(data[first]))
        ++first;

    if (first == data.size())
        return "";  // all whitespace

    size_t last = data.size() - 1;
    while (last > first && std::isspace(data[last])) 
        --last;

    return data.substr(first, last - first + 1);
}