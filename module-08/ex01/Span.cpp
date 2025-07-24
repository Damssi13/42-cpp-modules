#include "Span.hpp"

Span::Span() : max_size(0) {}

Span::Span(unsigned int N) : max_size(N) {}

Span::Span(const Span& other) : numbers(other.numbers), max_size(other.max_size) {}

Span& Span::operator= (const Span& other)
{
    if(this != &other)
    {
        numbers = other.numbers;
        max_size = other.max_size;
    }
    return (*this);
}

Span::~Span() {}

void    Span::addNumber(int n)
{
    if(numbers.size() >= max_size)
        throw std::runtime_error("No left space to store a number\n");
    numbers.push_back(n);   
}

void    Span::shortestSpan()
{
    if(numbers.size() < 2)
        throw std::runtime_error("Not enough numbers for span\n");
    std::sort(numbers.begin(), numbers.end());
    size_t min_span = std::numeric_limits<size_t>::max();
    
}

void    Span::longestSpan()
{

}