#include "AForm.hpp"
#include "Bureaucrat.hpp"

//Defualt Constructor
Bureaucrat::Bureaucrat() : name("Default"), grade(10){
  std::cout << "Default constructor called!\n";
}

//Parameteric Constructor
Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name){
  if(grade > 150)
    throw GradeTooLowException();
  else if(grade < 1)
    throw GradeTooHighException();
  this->grade = grade;
  std::cout << "Bureaucrat Constructor called!\n";
}

//Copy Constructor
Bureaucrat::Bureaucrat(const Bureaucrat& other){
  std::cout << "Copy constructor called!\n";
  *this = other;
}
//Copy assignment
Bureaucrat  &Bureaucrat::operator=(const  Bureaucrat& other){
  std::cout << "Copy assignment called!\n";
  if(this != &other){
    grade = other.grade;
  }
  return *this;
}

const char * Bureaucrat::GradeTooHighException::what() const throw(){
  return "Bureaucrat::GradeTooHighException\n";
}

const char * Bureaucrat::GradeTooLowException::what() const throw(){
  return "Bureaucrat::GradeTooLowException\n";
}

const std::string Bureaucrat::getName()const{
  return name;
}

int Bureaucrat::getGrade()const {
  return grade;
}

void    Bureaucrat::signForm(AForm& form){
  try{
    form.beSigned(*this);
    std::cout << this->name << " signed " << form.getName() << std::endl;
  }catch(const std::exception& e){
    std::cout << this->name << " could not sign " << form.getName() << " because " << e.what();
  }
}

void Bureaucrat::executeForm(const AForm& form)const{
    form.execute(*this);
    std::cout << this->name << " executed " << form.getName() << std::endl;
}

// 1 ==> 2 
void Bureaucrat::decrementGrade(){
  if(grade + 1 > 150)
    throw GradeTooLowException();
  grade++;
}
//2 ==> 1
void Bureaucrat::incrementGrade(){
  if(grade - 1 < 1)
    throw GradeTooHighException();
  grade--;
}

Bureaucrat:: ~Bureaucrat(){
  std::cout << "Bureaucrat Destructor called\n";
}

std::ostream &operator<<(std::ostream &os, Bureaucrat &bureau){
    os << bureau.getName() << ", bureaucrat grade " << bureau.getGrade() << std::endl;
    return os;
}
