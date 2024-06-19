#include "WrongAnimal.hpp"

void WrongAnimal::makeSound(void) const {
    std::cout << "WrongAnimal sound..." << std::endl;
}

std::string WrongAnimal::getType(void) const{
    return this->type;
}

WrongAnimal::WrongAnimal(WrongAnimal const & rhs){
    *this = rhs;
    std::cout << "Constructor WrongAnimal copy called" << std::endl;
}

WrongAnimal & WrongAnimal::operator=(WrongAnimal const & rhs){
    type = rhs.type;
    return *this;
}

WrongAnimal::WrongAnimal() : type("WrongAnimal"){
    std::cout << "Constructor WrongAnimal default called" << std::endl;
}

WrongAnimal::~WrongAnimal(){
    std::cout << "Destructor WrongAnimal called" << std::endl;
}