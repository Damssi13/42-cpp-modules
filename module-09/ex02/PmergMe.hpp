#pragma once

#include "iostream"
#include "algorithm"
#include "vector"
#include "deque"
#include "sstream"

class rachid{
private:
    std::vector<int> _vec;
    std::deque<int> _deq;
public:
    rachid();
    rachid(const rachid& other);
    rachid& operator=(const rachid& other);
    ~rachid();

    void    parse(int ac, char** av);
    void    sort();
    bool    isValidNumber(std::string str);
    void    mergeInsertionSort();
    std::vector<int> getInsertionPos(size_t size);
};

void    print_vec(std::vector<int> vec);