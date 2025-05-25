#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat first("Rachid", 32);

    std::cout << first;
    first.increment();
    std::cout << first;
    first.increment();
    std::cout << first;
    first.increment();
    std::cout << first;

}
