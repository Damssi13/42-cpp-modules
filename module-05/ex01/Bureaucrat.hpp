#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP


#include <iostream>
#include <exception>

class Form;

class Bureaucrat{
private:
    const std::string name;
    int               grade;
public:
    Bureaucrat();
    Bureaucrat(const std::string& name, int grade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat  &operator= (const Bureaucrat& other);
    ~Bureaucrat();

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

    const std::string   getName()const;
    int                 getGrade()const;

    void incrementGrade();
    void decrementGrade();
    void    signForm(Form& form);

};

std::ostream  &operator<<(std::ostream &os, Bureaucrat &bureau);
#endif
