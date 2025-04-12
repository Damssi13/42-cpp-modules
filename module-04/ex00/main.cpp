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
    return 0;
}