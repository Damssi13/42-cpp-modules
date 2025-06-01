#include "Intern.hpp"

int main()
{
    Intern someRandomIntern;

    //Robotomy Request
    std::cout << "\n--- Test 1: robotomy request ---\n";
    AForm *AForm1 = someRandomIntern.makeForm("robotomy request", "Bender");
    if (AForm1) {
        std::cout << "AForm created: " << AForm1->getName() << "\n";
        delete AForm1;
    }

    //Shrubbery Creation
    std::cout << "\n--- Test 2: shrubbery creation ---\n";
    AForm *AForm2 = someRandomIntern.makeForm("shrubbery creation", "Home");
    if (AForm2) {
        std::cout << "AForm created: " << AForm2->getName() << "\n";
        delete AForm2;
    }

    //Presidential Pardon
    std::cout << "\n--- Test 3: presidential pardon ---\n";
    AForm *AForm3 = someRandomIntern.makeForm("presidential pardon", "School");
    if (AForm3) {
        std::cout << "AForm created: " << AForm3->getName() << "\n";
        delete AForm3;
    }

    //Invalid AForm name
    std::cout << "\n--- Test 4: invalid AForm name ---\n";
    AForm *AForm4 = someRandomIntern.makeForm("invalid AForm", "Nobody");
    if (!AForm4) {
        std::cout << "AForm creation failed (as expected).\n";
    }

}