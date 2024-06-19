#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#define NB_ANIMALS 10

int main()
{
/* // Constructor testing
    std::cout << "1. Constructor testing" << std::endl << std::endl;   

    // Dog testing
    std::cout << "---Dog class tests---" << std::endl;

    Dog test1;
    std::cout << "Type is: " << test1.getType() << " " << std::endl;
    std::cout << "Sound is: ";
    test1.makeSound();
    std::cout << std::endl;

    Dog test2(test1);
    std::cout << "Type is: " << test2.getType() << " " << std::endl;
    std::cout << "Sound is: ";
    test2.makeSound();
    std::cout << std::endl;

    // Cat testing
    std::cout << "---Cat class tests---" << std::endl;

    Cat test3;
    std::cout << "Type is: " << test3.getType() << " " << std::endl;
    std::cout << "Sound is: ";
    test3.makeSound();
    std::cout << std::endl;
    
    Cat test4(test3);
    std::cout << "Type is: " << test4.getType() << " " << std::endl;
    std::cout << "Sound is: ";
    test4.makeSound();
    std::cout << std::endl;

    // Animal class testing
    std::cout  << std::endl << "---Animal class tests---" << std::endl;

    Animal test5;
    std::cout << "Type is: " << test5.getType() << " " << std::endl;
    std::cout << "Sound is: ";
    test5.makeSound();
    std::cout << std::endl;
    
    Animal test6(test5);
    std::cout << "Type is: " << test6.getType() << " " << std::endl;
    std::cout << "Sound is: ";
    test6.makeSound();
    std::cout << std::endl;

// Exercice testing
    const Animal *animals[NB_ANIMALS];
    for (int i = 0; i < NB_ANIMALS; i++ ){
        if ( i < (NB_ANIMALS / 2)){
            animals[i] = new Dog();
            std::cout << animals[i]->getType() << " " << std::endl;
            animals[i]->makeSound();
            std::cout << std::endl;
        }
        else{
            animals[i] = new Cat();
            std::cout << animals[i]->getType() << " " << std::endl;
            animals[i]->makeSound();     
            std::cout << std::endl;
        }
    }
    std::cout << "the addresses of the animal elements are: " << std::endl;
    for (int i = 0; i < NB_ANIMALS; i++ ){
        std::cout << animals[i] << std::endl;
    }
    std::cout << std::endl;

    for ( int i = 0; i < NB_ANIMALS; i++ ) {
        delete animals[i];
    }
 */
    Dog basic;
    Dog temp;
    temp = basic;
    return 0;
}