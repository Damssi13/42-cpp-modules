#pragma once

#include <iostream>
#include <fstream>
#include <algorithm>
#include <stack>

class RPN{
private:
    std::stack<int> _stack;

public:
    RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);
    ~RPN();

    int     calculate(int a, int b, char token);
    void    processExpresstion(const std::string& expression);
    bool    validToken(int token);
};