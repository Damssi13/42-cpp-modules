#include "PmergMe.hpp"
int callStack = 0;
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
    print_vec(_vec);
}

//2147483647
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

void    print_vec(std::vector<int> vec)
{
    std::vector<int>::iterator vit = vec.begin();
    
    while(vit != vec.end())
    {
        std::cout << *vit << " ";
        vit++;
    }
    std::cout << std::endl;
}


void    rachid::mergeInsertionSort()
{
    callStack++;
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

    std::vector<std::vector<int> > pairs;
    for(int i = 0; i <  _vec.size(); i += 2)
    {
        int first = _vec[i];
        int second = _vec[i + 1];
        if(first > second)
            std::swap(first, second);
        pairs.push_back({first, second});
    }

    std::vector<int> winners;
    for(int i = 0;i < pairs.size(); i++)
        winners.push_back(pairs[i][1]);

    if(winners.size() > 1)
    {
        _vec = winners;
        mergeInsertionSort();
        winners = _vec;
    }


    std::vector<int> result = winners;

    std::cout << "call Stack number: " << callStack << std::endl;
    std::vector<int> losers;
    for(int i = 0; i < pairs.size(); i++)
        losers.push_back(pairs[i][0]);

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

std::vector<int>    rachid::getInsertionPos(size_t size)
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

std::vector<int>    getJacob(size_t size)
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
    
    return jacobsthal;//
}

void    rachid::sort()
{
    clock_t vecStart = clock();
    mergeInsertionSort();
    clock_t vecEnd = clock();

    clock_t deqStart = clock();
    mergeInsertionSort();
    clock_t deqEnd = clock();
}