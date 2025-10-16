#include "PmergMe.hpp"

template void rachid::printContainer<std::vector<int> >(const std::vector<int>);

rachid::rachid() {}

rachid::rachid(const rachid& other) : _vec(other._vec), _deq(other._deq) {}

rachid& rachid::operator=(const rachid& other)
{
    if(this != &other)
    {
        _deq = other._deq;
        _vec = other._vec;
    }
    return *this;
}   

rachid::~rachid() {}


void   rachid::parse(int ac, char **av)
{
    for(int i = 1; i < ac ; i++)
    {
        std::istringstream iss(av[i]);
        long num;
        iss >> num;
        // std::cout << num
        if(!isValidNumber(av[i]) || num > 2147483647)
            throw std::runtime_error("Error: Unvalid argument\n");
        _vec.push_back(num);
        _deq.push_back(num);
    }
    // print_vec(_vec);
}

std::vector<int> rachid::getInsertionPos(size_t size)
{
    std::vector<int> jacobSeq = getJacob(size);
    std::vector<int> order;
    std::vector<bool> used(size, false);
    used[0] = true;

    for (size_t i = 1; i < jacobSeq.size() && jacobSeq[i] < static_cast<int>(size); i++)//3
    {
        if (!used[jacobSeq[i]]) {
            order.push_back(jacobSeq[i]);
            used[jacobSeq[i]] = true;
        }
        
        for (int j = jacobSeq[i] - 1; j > jacobSeq[i-1]; j--) {// j = 5 
            if (j < (int)size && !used[j]) {
                order.push_back(j);
                used[j] = true;
            }
        }
    }

    for (size_t i = 1; i < size; i++) {
        if (!used[i]) {
            order.push_back(i);
        }
    }

    return order;
}
bool    rachid::isValidNumber(std::string str)
{
    if(str.empty())
        return false;
    for(size_t i = 0; i < str.size(); i++)
    {
        if(!std::isdigit(str[i]))
            return false;
    }
    return true;
}

template <typename Container> void    rachid::printContainer(Container cont)
{
    typename Container::iterator it = cont.begin();
    
    while(it != cont.end())
    {
        std::cout << *it << " ";
        it++;
    }
    std::cout << std::endl;
}



void    rachid::SortVec()
{
    if(_vec.size() <= 1)//base case
    return ;
    
    bool iSOdd = false;
    int oddNumber = 0;
    
    if(_vec.size() % 2 == 1)// is odd
    {
        iSOdd = true;
        oddNumber = _vec.back();
        _vec.pop_back();
    }
    
    std::vector<std::pair<int, int> > pairs;
    for(size_t i = 0; i <  _vec.size(); i += 2)
    {
        int first = _vec[i];
        int second = _vec[i + 1];
        if(first > second)
        std::swap(first, second);
        pairs.push_back(std::make_pair(first, second));
    }
    
    std::vector<int> winners;
    for(size_t i = 0;i < pairs.size(); i++)
    winners.push_back(pairs[i].second);
    
    if(winners.size() > 1)
    {
        _vec = winners;
        SortVec();
        winners = _vec;
    }
    
    
    std::vector<int> result = winners;
    
    std::vector<int> losers;
    for(size_t i = 0; i < pairs.size(); i++)
    losers.push_back(pairs[i].first);
    
    //if losers are full --> insert the first element of losers to the result
    if(!losers.empty())
    {
        std::vector<int>::iterator pos = std::lower_bound(result.begin(), result.end(), losers[0]);
        result.insert(pos, losers[0]);
    }
    
    //Insert the rest of the number using the jacobsthal sequence
    if(losers.size() > 1)
    {
        std::vector<int>  insertionOrder= getInsertionPos(losers.size());
        
        for (size_t i = 0; i < insertionOrder.size(); i++)
        {
            int idx = insertionOrder[i];
            if (idx > 0 && idx < (int)losers.size())
            {
                std::vector<int>::iterator pos = std::lower_bound(result.begin(), result.end(),  losers[idx]);
                result.insert(pos,  losers[idx]);
            }
        }
    }
    
    //if it's odd insert the oddNumber
    if(iSOdd)
    {
        std::vector<int>::iterator pos = std::lower_bound(result.begin(), result.end(), oddNumber);
        result.insert(pos, oddNumber);
    }
    
    _vec = result;
}

std::vector<int> rachid::getJacob(size_t size)
{
    std::vector<int> jacobsthal;
    jacobsthal.push_back(0);
    jacobsthal.push_back(1);
    
    while (jacobsthal.back() < static_cast<int>(size))
    {
        int lastNum = jacobsthal.back();
        int secondLastNum = jacobsthal[jacobsthal.size() - 2];
        
        int next = lastNum + 2 * secondLastNum;
        jacobsthal.push_back(next);
    }
    
    return jacobsthal;
}

////////////////////////////////////////////////////////////////////////////////////
void    rachid::SortDeq()
{
    if(_deq.size() <= 1)//base case
        return ;
    
    bool iSOdd = false;
    int oddNumber = 0;
    
    if(_deq.size() % 2 == 1)// is odd
    {
        iSOdd = true;
        oddNumber = _deq.back();
        _deq.pop_back();
    }
    
    std::vector<std::pair<int, int> > pairs;
    for(size_t i = 0; i <  _deq.size(); i += 2)
    {
        int first = _deq[i];
        int second = _deq[i + 1];
        if(first > second)
            std::swap(first, second);
        pairs.push_back(std::make_pair(first, second));
    }
    
    std::deque<int> winners;
    for(size_t i = 0;i < pairs.size(); i++)
    winners.push_back(pairs[i].second);
    
    if(winners.size() > 1)
    {
        _deq = winners;
        SortDeq();
        winners = _deq;
    }
    
    
    std::deque<int> result = winners;
    
    std::deque<int> losers;
    for(size_t i = 0; i < pairs.size(); i++)
    losers.push_back(pairs[i].first);
    
    //if losers are full --> insert the first element of losers to the result
    if(!losers.empty())
    {
        std::deque<int>::iterator pos = std::lower_bound(result.begin(), result.end(), losers[0]);
        result.insert(pos, losers[0]);
    }
    
    //Insert the rest of the number using the jacobsthal sequence
    if(losers.size() > 1)
    {
        std::vector<int>  insertionOrder= getInsertionPos(losers.size());
        
        for (size_t i = 0; i < insertionOrder.size(); i++)
        {
            int idx = insertionOrder[i];
            if (idx > 0 && idx < (int)losers.size())
            {
                std::deque<int>::iterator pos = std::lower_bound(result.begin(), result.end(),  losers[idx]);
                result.insert(pos,  losers[idx]);
            }
        }
    }
    
    //if it's odd insert the oddNumber
    if(iSOdd)
    {
        std::deque<int>::iterator pos = std::lower_bound(result.begin(), result.end(), oddNumber);
        result.insert(pos, oddNumber);
    }
    
    _deq = result;
}

void    rachid::sort()
{
    std::cout << "Before: ";
    printContainer(_vec);
   
    clock_t vecStart = clock();
    SortVec();
    std::cout << "After: ";
    printContainer(_vec);

    clock_t vecEnd = clock();
    double vecTime = static_cast<double>(vecEnd - vecStart) / CLOCKS_PER_SEC * 1000000;
    
    clock_t deqStart = clock();
    SortDeq();
    clock_t deqEnd = clock();
    double deqTime = static_cast<double>(deqEnd - deqStart) / CLOCKS_PER_SEC * 1000000;


    std::cout << "Time to process a range of " << _vec.size()
              << " elements with std::vector : " << std::fixed << std::setprecision(5)
              << vecTime << " us" << std::endl;

    std::cout << "Time to process a range of " << _deq.size()
              << " elements with std::deque : " << std::fixed << std::setprecision(5)
              << deqTime << " us" << std::endl;
}
