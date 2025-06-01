#include "Bureaucrat.hpp"


int main() {
    std::cout << "\n--- Testing valid creation ---\n";
    try {
        Bureaucrat a("Rachid", 42);
        std::cout << a;
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << '\n';
    }
    
    std::cout << "\n--- Testing invalid high grade (grade = 0) ---\n";
    try {
        Bureaucrat b("Amine", -21);
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << '\n';
    }
    
    std::cout << "\n--- Testing invalid low grade (grade = 200) ---\n";
    try {
        Bureaucrat c("Jaki", 200);
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << '\n';
    }
    
    std::cout << "\n--- Testing increment and decrement ---\n";
    try {
        Bureaucrat d("David", 2);
        std::cout << d;

        d.incrementGrade();  // 2 → 1 (ok)
        std::cout << "After increment: grade " << d.getGrade() << "\n";

        d.incrementGrade();  // 1 → 0 (should throw)
        std::cout << "After second increment: grade " << d.getGrade() << "\n";
    }
    catch (std::exception& e) {
        std::cerr << "Exception during increment: " << e.what() << '\n';
    }
    
    std::cout << "\n--- Testing decrement at low boundary ---\n";
    try {
        Bureaucrat e("Med", 149);
        std::cout << e;

        e.decrementGrade();  // 149 → 150 (ok)
        std::cout << "After decrement: grade " << e.getGrade() << "\n";

        e.decrementGrade();  // 150 → 151 (should throw)
        std::cout << "After second decrement: grade " << e.getGrade() << "\n";
    }
    catch (std::exception& e) {
        std::cerr << "Exception during decrement: " << e.what() << '\n';
    }

    return 0;
}

