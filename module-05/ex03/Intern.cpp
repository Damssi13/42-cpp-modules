#include "Intern.hpp"


Intern::Intern(){
    // std::cout << "Intern Constructor called!\n";
}

Intern::Intern(const Intern& other){
    // std::cout << "Copy Constructor called!\n";
    *this = other;
}

Intern& Intern::operator=(const Intern& other){
    (void)other;
    return *this;
}

Intern::~Intern(){
    // std::cout << "Intern Destructor called!\n";
}

AForm *Intern::makeForm(std::string name, std::string target)
{
    AForm*  (*Forms[])(std::string&) = {
        &PresidentialPardonForm::createForm,
        &RobotomyRequestForm::createForm,
        &ShrubberyCreationForm::createForm
    };
    std::string array[] = {
        "presidential pardon",
        "robotomy request",
        "shrubbery creation"
    };
    for(int i = 0; i < 3; i++)
    {
        if(array[i] == name)
        {
            std::cout << "Intern creates " << name << std::endl;
            return Forms[i](target);
        }
    }
    std::cerr << "Form name not found!\n";
    return NULL;
}