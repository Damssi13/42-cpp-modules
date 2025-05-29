#include "Form.hpp"

//CONSTRUCTORS AND DESTRUCTORS

Form::Form() : name("Default"), isSigned(false), gradeSign(10), gradeExec(10){
    std::cout << "Default constructor\n";
}

Form::Form(const std::string name, const int gradeSign, const int gradeExec) : 
name(name), isSigned(false), gradeSign(gradeSign), gradeExec(gradeExec){
    
    if(gradeSign > 150 || gradeExec > 150)
        throw GradeTooLowException();
    if (gradeSign < 1 || gradeExec < 1)
        throw GradeTooHighException();
    
    std::cout << "Form constructor called!\n";
}

Form::Form(const Form& other) : 
isSigned(other.isSigned), gradeSign(other.gradeSign), gradeExec(other.gradeExec){
    std::cout << "Copy constructor called\n";
}

Form& Form::operator=(const Form& other){
    if(this != &other)
        isSigned = other.isSigned;
    return *this;
}

Form::~Form(){
    std::cout << "Destructor called!\n";
}

void    Form::beSigned(Bureaucrat& bureau)
{
    if(bureau.getGrade() > gradeSign)
        throw GradeTooLowException();
    isSigned = true;
}

//EXCEPTIONS
const char* Form::GradeTooHighException::what() const throw(){
    return "Form::GradeTooHighException\n";
} 

const char* Form::GradeTooLowException::what() const throw(){
    return "Form::GradeTooLowException\n";
} 

//GETTERS
std::string     Form::getName() const{
    return name;
}

bool    Form::getIsSigned() const{
    return isSigned;
}

int   Form::getGradeSign() const{
    return gradeSign;
}

int   Form::getGradeExec() const{
    return gradeExec;
}

std::ostream&   operator<< (std::ostream& os, Form& form){
    os  << "Name:" << form.getName()
        << ". Gradesign:" << form.getGradeSign()
        << ". GradeExec:" << form.getGradeExec()
        << ". Is it signed: " << (form.getIsSigned() ? "YES" : "NO")
        << std::endl;
    return os;
}

