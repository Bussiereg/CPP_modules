#include "Animal.hpp"

void Animal::makeSound(void) const {
    std::cout << "Animal sound..." << std::endl;
}

std::string Animal::getType(void) const{
    return this->type;
}

Animal::Animal(Animal const & rhs){
    *this = rhs;
    std::cout << "Constructor Animal copy called" << std::endl;
}

Animal & Animal::operator=(Animal const & rhs){
    type = rhs.type;
    return *this;
}

Animal::Animal() : type("Animal"){
    std::cout << "Constructor Animal default called" << std::endl;
}

Animal::~Animal(){
    std::cout << "Destructor Animal called" << std::endl;
}