#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"


class AForm{
private:
    const std::string   name;
    bool                isSigned;
    const int           gradeSign;
    const int           gradeExec;

public:
    //constructor and destructors
    AForm();
    AForm(const std::string name, const int gradeSign, const int gradeExec);
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    virtual ~AForm();
    
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

    class FormNotSignedException : public std::exception
    {
    public:
        const char* what() const throw();
    };

    virtual void    execute(const Bureaucrat& executor) const = 0;
    
    
    // getters
    std::string     getName() const;
    bool            getIsSigned() const;
    int             getGradeSign() const;
    int             getGradeExec() const;    
    void    beSigned(Bureaucrat& bureau);
};

std::ostream&   operator<< (std::ostream&   os, AForm& form);

#endif