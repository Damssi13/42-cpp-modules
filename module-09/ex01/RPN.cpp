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

void    RPN::processExpresstion(const std::string& expression)
{
    bool spaceFlag = false;
    char   token;

    if(expression.empty())
        throw std::runtime_error("Error: Unvalid expression\n");
    for(size_t i = 0; i < expression.length(); i++)
    {
        if(std::isdigit(expression[i]))
        {
            if(spaceFlag)
                throw std::runtime_error("Error: Space required\n");
            _stack.push(expression[i] - '0');
            spaceFlag = true;
        }
        else if(validToken(expression[i]))
        {
            if(spaceFlag)
                throw std::runtime_error("Error: Space required\n");
            if( _stack.size() < 2)
                throw std::runtime_error("Error: Mismatch between digits and operators count\n"); 

            token = expression[i];
            int top, btop;
            top = _stack.top();
            _stack.pop();
            btop = _stack.top();
            _stack.pop();    
            _stack.push(calculate(btop, top, token));            
            spaceFlag = true;
        }
        else if(expression[i] == ' ')
            spaceFlag = false;

        else
            throw std::runtime_error("Error: Unvalid token\n");
    }
    if(_stack.empty())
        throw std::runtime_error("Error: Unvalid expression\n");
    if(_stack.size() > 1)
        throw std::runtime_error("Error: Mismatch between digits and operators count\n"); 
    std::cout << _stack.top() << std::endl;
}

bool    RPN::validToken(int token)
{
    if(token == '+' || token == '-' || token == '*' || token == '/')
        return true;
    return false;
}

int     RPN::calculate(int a, int b, char token)
{
    switch(token){
        case '+':
            return a + b;
            break;
        case '-':
            return a - b;
            break;
        case '*':
            return a * b;
            break;
        case '/':
            if(b == 0)
                throw std::runtime_error("Error: Division by zero");
            return a / b;
            break;
    }
    return 0;
}