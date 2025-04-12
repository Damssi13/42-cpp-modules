#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int main()
{
    std::cout << "\n===============================\n";
    std::cout << "\n=====Constructing======\n";

    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << "\n===============================\n";
    std::cout << "\n======GettingType=======\n";

    std::cout << i->getType() << " " << std::endl;
    std::cout << j->getType() << " " << std::endl;
    std::cout << meta->getType() << " " << std::endl;
    std::cout << "\n===============================\n";
    std::cout << "\n=======MakeSound=======\n";

    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();
    std::cout << "\n===============================\n";
    std::cout << "\n=======Destruction=======\n";
    delete i;
    delete j;
    delete meta;
    std::cout << "\n===============================\n";
    std::cout << "\n===============================\n";

    WrongAnimal *wrong = new WrongAnimal();
    WrongAnimal *wrongCat = new WrongCat();
    
    std::cout << std::endl;

    std::cout << wrong->getType() << " " << std::endl;
    std::cout << wrongCat->getType() << " " << std::endl;
    std::cout << std::endl;

    wrong->makeSound();
    wrongCat->makeSound();

    std::cout << std::endl;
    
    delete wrong;
    delete wrongCat;
    return 0;
}