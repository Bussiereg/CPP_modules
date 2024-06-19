#include "AAnimal.hpp"

std::string AAnimal::getType(void) const{
    return this->type;
}

AAnimal::AAnimal(AAnimal const & rhs){
    *this = rhs;
    std::cout << "Constructor AAnimal copy called" << std::endl;
}

AAnimal & AAnimal::operator=(AAnimal const & rhs){
    type = rhs.type;
    return *this;
}

AAnimal::AAnimal() : type("AAnimal"){
    std::cout << "Constructor AAnimal default called" << std::endl;
}

AAnimal::~AAnimal(){
    std::cout << "Destructor AAnimal called" << std::endl;
}