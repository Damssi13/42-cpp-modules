#include "RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm() :
    AForm("Defualt", 72, 45), target("Default"){
    // std::cout << "Default constructor called!";
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) :
    AForm(target, 72, 45), target(target){
    // std::cout << "Robotomy constructor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other){
    *this = other;
    // std::cout << "Copy constructor called\n";
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other){
    if(this != &other)
        target = other.target;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(){
    // std::cout << "Robotomy Destructor called!\n";
}


void    RobotomyRequestForm::execute(const Bureaucrat& executor)const{

    if(!getIsSigned())
        throw FormNotSignedException();

    if(getGradeExec() < executor.getGrade())
        throw GradeTooLowException();
        
    std::cout << "BUZZZZZZZZZZZZZZZZZZZT...   ";

    std::srand(std::time(0));
    if(std::rand() % 2 )
        std::cout << getName() << " has been robotomized\n";
    else
        std::cout << "Robotomy failed !\n";
}