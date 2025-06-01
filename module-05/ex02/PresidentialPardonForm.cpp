#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() :
    AForm("Defualt", 25, 5), target("Default"){
    // std::cout << "Default constructor called!\n";
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) :
    AForm(target, 25, 5), target(target){
    // std::cout << "Presidential constructor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other){
    *this = other;
    // std::cout << "Copy constructor called\n";
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other){
    if(this != &other)
        target = other.target;
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(){
    // std::cout << "Presidential Destructor called!\n";
}

void    PresidentialPardonForm::execute(const Bureaucrat& executor)const{
    if(!getIsSigned())
        throw FormNotSignedException();
    if(getGradeExec() < executor.getGrade())
        throw GradeTooLowException();

    std::cout << executor.getName() << " has been pardoned by Zaphod Beeblebrox.\n";
}