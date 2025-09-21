#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& other) : _stack(other._stack) {}

RPN& RPN::operator=(const RPN& other)
{
    if(this != &other)
        _stack = other._stack;
    return *this;
}

RPN::~RPN() {}

//FIRST CASE : 2 4 + 3 -
//SECOND CASE : 2 + 4 - 3
//THIRD CASE : + 2 4 - 3
//FOUTH CASE : 2 4 3 + -

void    RPN::processExpresstion(std::string& expression)
{
    for(size_t i = 0; i < expression.length(); i++)
    {
        if(std::isdigit(expression[i]))
            _stack.push(atoi(expression[i]));
        else
        {
            if(validToken(expression[i]))
            {
                _operator = expression[i];
                //you count the top with before the top
                int top, btop;
                top = _stack.top();
                _stack.pop();
                btop = _stack.top();
                
            }

        }
    }
}

bool    RPN::validToken(int token)
{
    if(token == '+' || token == '-' || token == '*' || token == '/')
        return true;
    return false;
}