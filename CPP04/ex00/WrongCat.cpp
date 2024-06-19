#include "WrongCat.hpp"

void WrongCat::makeSound(void) const {
    std::cout << "Baaaaaa" << std::endl;
}

WrongCat::WrongCat(WrongCat const & rhs) : WrongAnimal(rhs){
    *this = rhs;
    std::cout << "Constructor WrongCat copy called" << std::endl;
}

WrongCat & WrongCat::operator=(WrongCat const & rhs){
    type = rhs.type;
    return *this;
}

WrongCat::WrongCat() : WrongAnimal(){
    type = "WrongCat";
    std::cout << "Constructor WrongCat default called" << std::endl;
}

WrongCat::~WrongCat(){
    std::cout << "Destructor WrongCat called" << std::endl;
}