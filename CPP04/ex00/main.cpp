#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

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

    // WrongAnimal class testing
    std::cout  << std::endl << "---WrongAnimal class tests---" << std::endl;

    WrongAnimal test7;
    std::cout << "Type is: " << test7.getType() << " " << std::endl;
    std::cout << "Sound is: ";
    test7.makeSound();
    std::cout << std::endl;
    
    WrongAnimal test8(test7);
    std::cout << "Type is: " << test8.getType() << " " << std::endl;
    std::cout << "Sound is: ";
    test8.makeSound();
    std::cout << std::endl;

    // WrongCat testing
    std::cout << "---WrongCat class tests---" << std::endl;

    WrongCat test9;
    std::cout << "Type is: " << test9.getType() << " " << std::endl;
    std::cout << "Sound is: ";
    test9.makeSound();
    std::cout << std::endl;
    
    WrongCat test10(test9);
    std::cout << "Type is: " << test10.getType() << " " << std::endl;
    std::cout << "Sound is: ";
    test10.makeSound();
    std::cout << std::endl;

    // Exercise testing
    std::cout << "2. Exercise testing" << std::endl << std::endl;  

    std::cout << "---Real animal tests---" << std::endl;  
    const Animal* meta = new Animal();

    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << meta->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();
    delete meta;
    delete i;
    delete j;
    std::cout << std::endl;

    std::cout << "---Wrong animal tests---" << std::endl;  
    const WrongAnimal* meta2 = new WrongAnimal();
    const WrongAnimal* k = new WrongCat();
    const WrongAnimal* m = new WrongCat();
    std::cout << k->getType() << " " << std::endl;
    std::cout << m->getType() << " " << std::endl;
    std::cout << meta2->getType() << " " << std::endl;
    m->makeSound();
    k->makeSound();
    meta2->makeSound();
    std::cout << std::endl << "---Destructor called---" << std::endl;
    delete meta2;
    delete m;
    delete k; */

    const Animal* j = new Dog();
    delete j;

    return 0;
}