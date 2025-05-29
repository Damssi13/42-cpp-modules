#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class Form{
private:
    const std::string   name;
    bool                isSigned;
    const int           gradeSign;
    const int           gradeExec;

public:
    //constructor and destructors
    Form();
    Form(const std::string name, const int gradeSign, const int gradeExec);
    Form(const Form& other);
    Form& operator=(const Form& other);
    ~Form();
    
    //execeptions
    class GradeTooLowException : public std::exception
    {
    public:
        const char* what() const throw();
    };

    class GradeTooHighException : public std::exception
    {
    public:
        const char* what() const throw();
    };


    void    beSigned(Bureaucrat& bureau);

    
    // getters
    std::string     getName() const;
    bool            getIsSigned() const;
    int             getGradeSign() const;
    int             getGradeExec() const;    
};

std::ostream&   operator<< (std::ostream&   os, Form& form);

#endif