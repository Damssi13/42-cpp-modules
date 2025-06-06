#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm{
private:
    std::string target;

public:
    PresidentialPardonForm();
    PresidentialPardonForm(const std::string& target);
    PresidentialPardonForm(const PresidentialPardonForm& other);
    PresidentialPardonForm&  operator= (const PresidentialPardonForm& other);
    ~PresidentialPardonForm();

    void    execute(const Bureaucrat& executor) const;
    static AForm    *createForm(std::string& target);
};


#endif