#include "ShrubberyCreationForm.hpp"


ShrubberyCreationForm::ShrubberyCreationForm() :
    AForm("Defualt", 145, 137), target("Default"){
    // std::cout << "Default constructor called!";
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) :
    AForm(target, 145, 137), target("Default"){
    // std::cout << "Shrubbery constructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other){
    *this = other;
    // std::cout << "Copy constructor called\n";
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other){
    if(this != &other)
        target = other.target;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
    // std::cout << "Shrubbery Destructor called!\n";
}

void    ShrubberyCreationForm::execute(const Bureaucrat& executor)const{
    if(!getIsSigned())
        throw FormNotSignedException();
    if(getGradeExec() < executor.getGrade())
        throw GradeTooLowException();
    

    std::ofstream file((getName() + "_shrubbery").c_str());
    if(!file.is_open())
        throw std::ios_base::failure("Failed to create a file");
    
    file    << "       /\\\n"
            << "      /  \\\n"
            << "     /   o\\\n"
            << "    /o    o\\\n"
            << "   /--------\\\n"
            << "      | |   \n"
            << "      | |    \n";
}

AForm   *ShrubberyCreationForm::createForm(std::string& target){
    return new ShrubberyCreationForm(target);
}