#pragma once

#include "iostream"
#include "algorithm"
#include "vector"
#include "deque"
#include "sstream"
#include "iomanip"

class PmergeMe{
private:
    std::vector<int> _vec;
    std::deque<int> _deq;
public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    void    parse(int ac, char** av);
    void    sort();
    bool    isValidNumber(std::string str);
    void    SortVec();
    void    SortDeq();

    std::vector<int> getInsertionPos(size_t size);
    std::vector<int> getJacob(size_t size);
    
    template <typename Container>
    void    printContainer(Container cont);
};