#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

#define arraySize 10

int main()
{
    std::cout << "===========ANIMAL BASIC TEST=======\n\n" << std::endl;
    Animal *animals[arraySize];
    for (int i = 0; i < arraySize / 2; i++)
    {
        animals[i] = new Dog();
    }
    for (int i = arraySize / 2; i < arraySize; i++)
    {
        animals[i] = new Cat();
    }
    for (int i = 0; i < arraySize; i++)
    {
        animals[i]->makeSound();
    }
    for (int i = 0; i < arraySize; i++)
    {
        delete animals[i];
    }
    std::cout << "===========DOG SET IDEA BRAIN=======\n\n" << std::endl;
    Dog dog;
    Dog dog2;
    dog2 = dog;
    dog.getBrain()->setIdea(0,"I am a dog");
    dog2.getBrain()->setIdea(0, "I am a dog2");
    std::cout << dog.getBrain()->getIdea(0) << std::endl;
    std::cout << dog2.getBrain()->getIdea(0) << std::endl;
    std::cout << "===========CAT SET IDEA BRAIN=======\n\n" << std::endl;
    Cat cat;
    Cat cat2(cat);
    cat.getBrain()->setIdea(3,"I am a cat");
    cat2.getBrain()->setIdea(3, "I am a cat2");
    std::cout << cat.getBrain()->getIdea(0) << std::endl;
    std::cout << cat2.getBrain()->getIdea(0) << std::endl;
    std::cout << "===========BRAIN SET IDEA=======\n\n" << std::endl;
    Brain *brain = new Brain();
    brain->setIdea(3, "I am a brain");
    std::cout << brain->getIdea(0) << std::endl;
    delete brain;
    std::cout << "===========DESTRUCTOR=======\n\n" << std::endl;

}