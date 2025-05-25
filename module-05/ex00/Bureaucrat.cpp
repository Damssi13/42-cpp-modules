#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name), grade(grade)
{
  try{
    if(grade > 150)
      throw "GradeTooLowException";
    else if(grade < 1)
      throw "GradeTooHighException"
  }
  std::cout << "Bureaucrat Constructor called!\n";
}

const std::string Bureaucrat::getName(){
  return name;
}

int Bureaucrat::getGrade(){
  return grade;
}

void decrementGrade() {
  grade++;
}

void incrementGrade() {
  try{
    if(grade)
  }
  grade--;
}

Bureaucrat:: ~Bureaucrat(){
  std::cout << "Bureaucrat Destructor called\n";
}

std::ostream &operator<<(std::ostream &os, Bureaucrat &bureau)
{
    os << bureau.getName() << ", bureaucrat grade " << bureau.getGrade() << std::endl;
    return os;
}
