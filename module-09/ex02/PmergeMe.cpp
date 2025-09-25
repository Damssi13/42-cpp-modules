#include "PmergMe.hpp"

rachid::rachid() {}

rachid::rachid(const rachid& other) : _vec(other._vec), _deq(other._deq) {}

rachid& rachid::operator=(const rachid& other)
{
    if(this != &other)
    {
        _deq = other._deq;
        _vec = other._vec;
    }
    return *this;
}

rachid::~rachid() {}


void   rachid::parse(int ac, char **av)
{
    for(int i = 1; i < ac ; i++)
    {
        std::istringstream iss(av[i]);
        long num;
        iss >> num;
        // std::cout << num
        if(!isValidNumber(av[i]) || num > 2147483647)
            throw std::runtime_error("Error: Unvalid argument\n");
        _vec.push_back(num);
        _deq.push_back(num);
    }
    print_vec(_vec);
}

//2147483647
bool    rachid::isValidNumber(std::string str)
{
    if(str.empty())
        return false;
    for(size_t i = 0; i < str.size(); i++)
    {
        if(!std::isdigit(str[i]))
            return false;
    }
    return true;
}

void    print_vec(std::vector<unsigned int> vec)
{
    std::vector<unsigned int>::iterator vit = vec.begin();
    
    while(vit != vec.end())
    {
        std::cout << *vit << " ";
        vit++;
    }
    std::cout << std::endl;
}