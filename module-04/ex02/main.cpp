#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

#define arraySize 10

int main()
{
    // Animal obj;


    std::cout << "\n=== Test 1: Basic Construction and Sound ===\n" << std::endl;
    {
        Cat cat;
        Dog dog;
        cat.makeSound(); // Should print "Meow!"
        dog.makeSound(); // Should print "Woof!"
        std::cout << "Cat type: " << cat.getType() << std::endl; // Should print "Cat"
        std::cout << "Dog type: " << dog.getType() << std::endl; // Should print "Dog"
        std::cout << "-----------\n";

    }

    std::cout << "\n=== Test 2: Copy Constructor (Deep Copy) ===\n" << std::endl;
    {
        Cat original;
        std::cout << "-----------\n";
        original.getBrain()->setIdea(0, "Chase mouse");
        Cat copy(original); // Copy constructor
        std::cout << "-----------\n";

        copy.getBrain()->setIdea(0, "Sleep"); // Modify copy
        std::cout << "Original idea: " << original.getBrain()->getIdea(0) << std::endl; // Should print "Chase mouse"
        std::cout << "Copy idea: " << copy.getBrain()->getIdea(0) << std::endl; // Should print "Sleep"
        std::cout << "-----------\n";

    }

    std::cout << "\n=== Test 3: Copy Assignment (Deep Copy) ===\n" << std::endl;
    {
        Dog original;
        std::cout << "-----------\n";

        original.getBrain()->setIdea(0, "Fetch ball");
        Dog assigned;
        std::cout << "-----------\n";

        assigned.getBrain()->setIdea(0, "Bark");
        assigned = original; // Copy assignment
        assigned.getBrain()->setIdea(0, "Run"); // Modify assigned
        std::cout << "-----------\n";

        std::cout << "Original idea: " << original.getBrain()->getIdea(0) << std::endl; // Should print "Fetch ball"
        std::cout << "Assigned idea: " << assigned.getBrain()->getIdea(0) << std::endl; // Should print "Run"
        std::cout << "-----------\n";

    }

    std::cout << "\n=== Test 4: Polymorphism with Base Pointer ===\n" << std::endl;
    {
        Animal* cat = new Cat();
        std::cout << "-----------\n";

        Animal* dog = new Dog();
        std::cout << "-----------\n";

        cat->makeSound(); // Should print "Meow!"
        dog->makeSound(); // Should print "Woof!"
        std::cout << "Cat type: " << cat->getType() << std::endl; // Should print "Cat"
        std::cout << "Dog type: " << dog->getType() << std::endl; // Should print "Dog"
        delete cat;
        std::cout << "-----------\n";

        delete dog; // Tests virtual destructor
    }

    std::cout << "\n=== Test 5: Self-Assignment ===\n" << std::endl;
    {
        Cat cat;
        std::cout << "-----------\n";
        cat.getBrain()->setIdea(0, "Purr");
        cat = cat; // Self-assignment
        std::cout << "After self-assignment: " << cat.getBrain()->getIdea(0) << std::endl; // Should print "Purr"
        std::cout << "-----------\n";

    }

}