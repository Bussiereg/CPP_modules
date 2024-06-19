#include "Dog.hpp"

std::string * Dog::getIdeas(void){
    return dogBrain->getIdeas();
}

void Dog::makeSound(void) const {
    std::cout << "Woof!" << std::endl;
}

Dog::Dog(Dog const & rhs) : AAnimal(rhs){    
    *this = rhs;
    std::cout << "Constructor Dog copy called" << std::endl;
}

Dog & Dog::operator=(Dog const & rhs){
    type = rhs.type;
    dogBrain = new Brain;
    return *this;
}

Dog::Dog() : AAnimal(){
    type = "Dog";
    dogBrain = new Brain();
    std::cout << "Constructor Dog default called" << std::endl;
}

Dog::~Dog(){
    delete dogBrain;
    std::cout << "Destructor Dog called" << std::endl;
}