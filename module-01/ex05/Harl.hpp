#ifndef HARL_HPP
#define HARL_HPP

#include <string>
#include <iostream>

class Harl{
private:
    void    debug();
    void    info();
    void    warning();
    void    error();

public:
    void    complain(std::string level);
};


#endif
