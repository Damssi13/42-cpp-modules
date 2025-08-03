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
        throw std::runtime_error("No left space to store a number");
    numbers.push_back(n);
}

int    Span::shortestSpan()
{
    if(numbers.size() < 2)
        throw std::runtime_error("Not enough numbers for span");
    std::sort(numbers.begin(), numbers.end());

    int shortest = std::numeric_limits<int>::max();

    std::vector<int>::iterator it = numbers.begin();
    std::vector<int>::iterator sec_it = ++numbers.begin();
    
    while(sec_it != numbers.end())
    {
        if((*sec_it - *it) < shortest)
            shortest = *sec_it - *it;
        it++;
        sec_it++;
    }
    return shortest;
}

int    Span::longestSpan()
{
    if(numbers.size() < 2)
        throw std::runtime_error("Not enough numbers for span");

    int max = *std::max_element(numbers.begin(), numbers.end());
    int min = *std::min_element(numbers.begin(), numbers.end());
    return(max - min);
}


// int Span::biggest()
// {
//     std::sort(numbers.begin(), numbers.end());
//     return *--numbers.end();
// }

// int Span::smallest()
// {
//     std::sort(numbers.begin(), numbers.end());
//     return *numbers.begin();
// }
