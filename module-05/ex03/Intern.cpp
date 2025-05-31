#include "Intern.hpp"


Intern::Intern()
{}

Intern::Intern(const Intern& other)
{}

Intern& Intern::operator=(const Intern& other)
{}

Intern::~Intern()
{}

AForm *Intern::makeForm(std::string& name, std::string& target)
{
    AForm*  (*Forms[])(std::string&) = {
        &PresidentialPardonForm::createForm,
        &RobotomyRequestForm::createForm,
        &ShrubberyCreationForm::createForm
    };
    }
}