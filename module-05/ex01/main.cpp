#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {

    try {
        Bureaucrat rachid("rachid", 2);
        Bureaucrat anas("anas", 60);
        
        Form taxForm("TaxForm", 1, 5);
        Form leaveForm("LeaveForm", 100, 100);
        
        std::cout << rachid << std::endl;
        std::cout << anas << std::endl;
        std::cout << taxForm << std::endl;
        std::cout << leaveForm << std::endl;
        
        // rachid can not sign (1 < 2)
        rachid.signForm(taxForm);
        
        // rachid can sign (100 > 2)
        rachid.signForm(leaveForm); 
        
        // anas can sign (100 > 40)
        anas.signForm(leaveForm);  
        
        // Test beSigned explicitly and catching exception
        Form contract("Contract", 50, 50);
        std::cout << contract << std::endl;
        
        try {
            contract.beSigned(anas);  // anas grade 60 -> too low -> should throw
        } catch (const std::exception& e) {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        }
        
        contract.beSigned(rachid);  // rachid grade 2 -> should succeed
        std::cout << contract << std::endl;
        return 0;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;

}
}