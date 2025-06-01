#include "AForm.hpp"

//CONSTRUCTORS AND DESTRUCTORS

AForm::AForm() : name("Default"), isSigned(false), gradeSign(10), gradeExec(10){
    // std::cout << "Default constructor\n";
}

AForm::AForm(const std::string name, const int gradeSign, const int gradeExec) : 
name(name), isSigned(false), gradeSign(gradeSign), gradeExec(gradeExec){
    
    if(gradeSign > 150 || gradeExec > 150)
        throw GradeTooLowException();
    if (gradeSign < 1 || gradeExec < 1)
        throw GradeTooHighException();
    // std::cout << "AForm constructor called!\n";
}

AForm::AForm(const AForm& other) : 
isSigned(other.isSigned), gradeSign(other.gradeSign), gradeExec(other.gradeExec){
    // std::cout << "Copy constructor called\n";
}

AForm& AForm::operator=(const AForm& other){
    if(this != &other)
        isSigned = other.isSigned;
    return *this;
}

AForm::~AForm(){
    // std::cout << "AForm Destructor called!\n";
}

void    AForm::beSigned(Bureaucrat& bureau)
{
    if(bureau.getGrade() > gradeSign)
        throw GradeTooLowException();
    isSigned = true;
}

//EXCEPTIONS
const char* AForm::GradeTooHighException::what() const throw(){
    return "AForm::GradeTooHighException\n";
} 

const char* AForm::GradeTooLowException::what() const throw(){
    return "AForm::GradeTooLowException\n";
}

const char* AForm::FormNotSignedException::what() const throw(){
    return "AForm::FormNotSignedException'\n";
}

//GETTERS
std::string     AForm::getName() const{
    return name;
}

bool    AForm::getIsSigned() const{
    return isSigned;
}

int   AForm::getGradeSign() const{
    return gradeSign;
}

int   AForm::getGradeExec() const{
    return gradeExec;
}

std::ostream&   operator<< (std::ostream& os, AForm& form){
    os  << "Name:" << form.getName()
        << ". Gradesign:" << form.getGradeSign()
        << ". GradeExec:" << form.getGradeExec()
        << ". Is it signed: " << (form.getIsSigned() ? "YES" : "NO")
        << std::endl;
    return os;
}

