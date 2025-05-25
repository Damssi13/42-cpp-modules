#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP


#include <iostream>
#include <exception>

class Bureaucrat{
private:
    const std::string name;
    int               grade;
public:
    Bureaucrat();
    Bureaucrat(const std::string& name, int grade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat  &operator= (const Bureaucrat& other);

    class GradeTooHighException : public std::exception
    {
    public:
        const char *what() const throw() ;
    };
    class GradeTooLowException : public std::exception
    {
    public:
        const char *what() const throw();
    };
    ~Bureaucrat();
    const std::string   getName();
    int                 getGrade();
    void incrementGrade();
    void decrementGrade();
};

std::ostream  &operator<<(std::ostream &os, Bureaucrat &bureau);
#endif
