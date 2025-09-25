#pragma once

#include "iostream"
#include "algorithm"
#include "vector"
#include "deque"
#include "sstream"

class rachid{
private:
    std::vector<unsigned int> _vec;
    std::deque<unsigned int> _deq;
public:
    rachid();
    rachid(const rachid& other);
    rachid& operator=(const rachid& other);
    ~rachid();

    void    parse(int ac, char** av);
    bool    isValidNumber(std::string str);
};

void    print_vec(std::vector<unsigned int> vec);