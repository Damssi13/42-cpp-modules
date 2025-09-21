#pragma once

#include <iostream>
#include <fstream>
#include <algorithm>
#include <stack>

class RPN{
private:
    std::stack<int> _stack;
    char _operator;

public:
    RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);
    ~RPN();


    void    processExpresstion(std::string& expression);
    bool    validToken(int token);
};