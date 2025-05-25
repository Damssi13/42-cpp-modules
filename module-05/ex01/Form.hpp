#ifndef FORM_HPP
#define FORM_HPP


#include <Bureaucrat.hpp>

class Form : public Bureaucrat{
private:
    const std::string   name;
    bool                isSigned;
    const int           gradeSign;
    const int           gradeExec;

public:
    Form();
    

    void    beSigned(Bureaucrat& crat);
    int     getName()

    ~Form();
};



#endif