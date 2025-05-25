#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP


#include <iostream>

class Bureaucrat{
private:
    const std::string name;
    int               grade;
public:
    Bureaucrat(const std::string name, int grade);

    ~Bureaucrat();
    const std::string   getName();
    int                 getGrade();
    void incrementGrade();
    void decrementGrade();
};

std::ostream  &operator<<(std::ostream &os, Bureaucrat &bureau);
#endif
