#include "Cat.hpp"

std::string * Cat::getIdeas(void){
    return catBrain->getIdeas();
}

void Cat::makeSound(void) const {
    std::cout << "Miaooow" << std::endl;
}

Cat::Cat(Cat const & rhs) : AAnimal(rhs){
    *this = rhs;
    std::cout << "Constructor Cat copy called" << std::endl;
}

Cat & Cat::operator=(Cat const & rhs){
    type = rhs.type;
    catBrain = new Brain;
    return *this;
}

Cat::Cat() : AAnimal(){
    type = "Cat";
    catBrain = new Brain();
    std::cout << "Constructor Cat default called" << std::endl;
}

Cat::~Cat(){
    delete catBrain;
    std::cout << "Destructor Cat called" << std::endl;
}