#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    Bureaucrat lowRank("LowRank", 150);
    Bureaucrat midRank("MidRank", 100);
    Bureaucrat highRank("HighRank", 1);

    ShrubberyCreationForm shrubbery("garden");
    RobotomyRequestForm robotomy("Bender");
    PresidentialPardonForm pardon("Ford");

    // 1) Signing failure (grade too low)
    std::cout << "\n-- Signing failure case --" << std::endl;
    try {
        shrubbery.beSigned(lowRank); // should throw exception
    } catch (std::exception& e) {
        std::cout << lowRank.getName() << " failed to sign shrubbery: " << e.what() << std::endl;
    }

    // 2) Executing unsigned form
    std::cout << "\n-- Executing unsigned form --" << std::endl;
    try{
        lowRank.executeForm(robotomy); // should fail (not signed)
    }catch(std::exception& e)
    {
        std::cout << "Exception:" << e.what() << std::endl;
    }

    // 3) Executing with grade too low
    std::cout << "\n-- Executing with grade too low --" << std::endl;
    try {
        robotomy.beSigned(highRank); // sign successfully
    } catch (...) {}
    lowRank.executeForm(robotomy); // lowRank grade too low to execute

    // 4) Successful sign and execute (Shrubbery) by midRank
    std::cout << "\n-- Successful sign & execute (Shrubbery) --" << std::endl;
    try {
        shrubbery.beSigned(midRank);
        std::cout << midRank.getName() << " signed " << shrubbery.getName() << std::endl;
    } catch (std::exception& e) {
        std::cout << midRank.getName() << " failed to sign: " << e.what() << std::endl;
    }
    midRank.executeForm(shrubbery);

    // 5) Successful sign and execute (Robotomy) by midRank signer, highRank executor
    std::cout << "\n-- Successful sign & execute (Robotomy) --" << std::endl;
    try {
        robotomy.beSigned(midRank);
        std::cout << midRank.getName() << " signed " << robotomy.getName() << std::endl;
    } catch (std::exception& e) {
        std::cout << midRank.getName() << " failed to sign: " << e.what() << std::endl;
    }
    highRank.executeForm(robotomy);

    // 6) Successful sign and execute (Pardon) by highRank
    std::cout << "\n-- Successful sign & execute (Pardon) --" << std::endl;
    try {
        pardon.beSigned(highRank);
        std::cout << highRank.getName() << " signed " << pardon.getName() << std::endl;
    } catch (std::exception& e) {
        std::cout << highRank.getName() << " failed to sign: " << e.what() << std::endl;
    }
    highRank.executeForm(pardon);

    // 7) Execute with borderline executor grade for Shrubbery
    std::cout << "\n-- Executing with borderline executor grade --" << std::endl;
    Bureaucrat borderline("Borderline", 137); // exec grade for Shrubbery
    try {
        shrubbery.beSigned(highRank); // sign with high rank
        std::cout << highRank.getName() << " signed " << shrubbery.getName() << std::endl;
    } catch (std::exception& e) {
        std::cout << highRank.getName() << " failed to sign: " << e.what() << std::endl;
    }
    borderline.executeForm(shrubbery);

    // 8) Multiple executions of Robotomy to show 50% success/fail chance
    std::cout << "\n-- Multiple executions of Robotomy for variability --" << std::endl;
    for (int i = 0; i < 5; ++i) {
        highRank.executeForm(robotomy);
    }

    return 0;
}