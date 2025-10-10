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
        std::vector<int> jacob = getInsertionPos(losers.size());
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