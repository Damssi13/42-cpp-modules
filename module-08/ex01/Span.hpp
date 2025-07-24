
#ifndef SPAN_HPP
#define SPAN_HPP


#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <exception>


class Span{
private:
    std::vector<int> numbers;
    unsigned int max_size;
public:
    Span();
    Span(unsigned int N);
    Span(const Span& other);
    Span&   operator= (const Span& other);
    ~Span();

    void    addNumber(int n);
    void    shortestSpan();
    void    longestSpan();
};

#endif