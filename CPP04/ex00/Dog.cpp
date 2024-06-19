#include "Dog.hpp"

void Dog::makeSound(void) const {
    std::cout << "Woof!" << std::endl;
}

Dog::Dog(Dog const & rhs) : Animal(rhs){    
    *this = rhs;
    std::cout << "Constructor Dog copy called" << std::endl;

}

Dog & Dog::operator=(Dog const & rhs){
    type = rhs.type;
    return *this;
}

Dog::Dog() : Animal(){
    type = "Dog";
    std::cout << "Constructor Dog default called" << std::endl;
}

Dog::~Dog(){
    std::cout << "Destructor Dog called" << std::endl;
}