#include "Cat.hpp"

void Cat::makeSound(void) const {
    std::cout << "Miaooow" << std::endl;
}

Cat::Cat(Cat const & rhs) : Animal(rhs){
    *this = rhs;
    std::cout << "Constructor Cat copy called" << std::endl;
}

Cat & Cat::operator=(Cat const & rhs){
    type = rhs.type;
    return *this;
}

Cat::Cat() : Animal(){
    type = "Cat";
    std::cout << "Constructor Cat default called" << std::endl;
}

Cat::~Cat(){
    std::cout << "Destructor Cat called" << std::endl;
}