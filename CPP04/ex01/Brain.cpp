#include "Brain.hpp"

std::string *Brain::getIdeas(void){
    return ideas;
}

Brain::Brain(){
    std::cout << "Constructor Brain default called" << std::endl;
}

Brain::Brain(Brain const & rhs){
    *this = rhs;
    std::cout << "Constructor Brain copy called" << std::endl;
}

Brain & Brain::operator=(Brain const & rhs){
	for (int i = 0; i < 100; i++ )
    	ideas[i] = rhs.ideas[i];
    return *this;
}

Brain::~Brain(){
    std::cout << "Destructor Brain called" << std::endl;
}