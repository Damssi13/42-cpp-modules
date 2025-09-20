#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string& file)
{
    (void)file;
    std::ifstream fdata(file.c_str());
    if(!fdata.is_open())
        throw std::runtime_error("Could not open the data file.");

    std::string line;
    getline(fdata, line);
    while(getline(fdata, line))
    {
        std::string date, rate;
        std::istringstream ss(line);
        if(getline(ss, date, ',') && getline(ss, rate))
        {
            float price = atof(rate.c_str());
            _table[date] = price;
        }
    }
    fdata.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _table(other._table), _strs(other._strs)  {} ///NEEDS TO EDIT

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if(this != &other)
    {
        _table = other._table;
        _strs = other._strs;
    }
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

    
    while(std::getline(filein, line))//it fills the _strs with the content of input.txt
    {
        if(++lines == 1)
            continue;
        _strs += parseLine(line) + "\n";
    }
    std::cout << _strs;
    filein.close();
    exit(1);


}

std::string    BitcoinExchange::parseLine(std::string& line)
{
    size_t pipe;
    float num;
    pipe =  line.find("|");
    if(pipe == std::string::npos)
        return "Unvalid format.";
    
    std::string date, value;

    date = trim(line.substr(0, pipe));
    value = trim(line.substr(pipe + 1));

    std::stringstream ss(value);
    ss >> num;
    if(!validDate(date))
        return ("Error: bad input => " + date);
    if(num > 1000)
        return "Error: too large number.";
    else if(num < 0 || ss.fail() || !ss.eof())
        return "Error: not a positive number.";

    date = trim(date);
    value = trim(value);
    std::map<std::string, float>::const_iterator cit = _table.lower_bound(date);//return the key if found if not returns greater value, if greater value does not exist either returns the end of the map
    // the key was smaller and not found
    if(cit->first != date)
    {
        if(cit != _table.begin() || cit == _table.end())
            cit--;
        else
            return "Error: No exchange rate available before the date: " + date;
    }
    std::stringstream result;
    result << date << " => "  << (num * cit->second);

    return result.str();

}


//   too large number
//   not a positive number
//   bad input -> 

bool BitcoinExchange::validDate(const std::string& date)
{
    if(date.length() != 10 || date[4] != '-' || date[7] != '-' )
        return false;
// std::cout << "DATE: " << date << std::endl;
    std::string m, d, y;
    m = date.substr(5, 2);
    d = date.substr(8, 2);
    y = date.substr(0, 4);

    if(!isDigits(y) || !isDigits(m) || !isDigits(d))
        return false;

    int month = atoi(m.c_str());
    int day = atoi(d.c_str());

    if(month > 12 || month <= 0 || day > 31 || day <= 0)
        return false;
    return true;

}


std::string trim(const std::string& data)
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

bool isDigits(const std::string& number)
{
    for(size_t i = 0; i < number.length(); i++)
    {
        if(!std::isdigit(number[i]))
            return false;
    }
    return true;
}