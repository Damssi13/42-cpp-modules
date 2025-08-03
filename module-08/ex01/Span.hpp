
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
    int    shortestSpan();
    int    longestSpan();

    template <typename iterator_T>
    void    addManyNumbers(iterator_T begin, iterator_T end)
    {
        while(begin != end)
        {
            if(numbers.size() >= max_size)
                throw std::runtime_error("No left space to store a number");
            numbers.push_back(*begin);
            begin++;
        }
    }
    // int     biggest();
    // int     smallest();
};

#endif