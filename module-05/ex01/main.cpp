#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {

    try {
        Bureaucrat bob("Bob", 2);
        Bureaucrat alice("Alice", 40);
        
        Form taxForm("TaxForm", 1, 5);
        Form leaveForm("LeaveForm", 100, 100);
        
        std::cout << bob << std::endl;
        std::cout << alice << std::endl;
        std::cout << taxForm << std::endl;
        std::cout << leaveForm << std::endl;
        
        // Bob tries to sign TaxForm (grade required = 1)
        bob.signForm(taxForm);  // Should fail (Bob grade 2 < 1 required)
        
        // Bob tries to sign LeaveForm (grade required = 100)
        bob.signForm(leaveForm);  // Should succeed
        
        // Alice tries to sign LeaveForm (grade required = 100)
        alice.signForm(leaveForm);  // Should succeed or fail depending if signed already
        
        // Test beSigned explicitly and catching exception
        Form contract("Contract", 50, 50);
        std::cout << contract << std::endl;
        
        try {
            contract.beSigned(alice);  // Alice grade 150 -> too low -> should throw
        } catch (const std::exception& e) {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        }
        
        contract.beSigned(bob);  // Bob grade 2 -> should succeed
        std::cout << contract << std::endl;
        return 0;
    }
    catch (const std::exception& e) {
        std::cerr << "Fatal error: " << e.what() << std::endl;

}
}