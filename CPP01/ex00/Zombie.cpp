#include "Zombie.hpp"

void Zombie::announce(void){
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string name) : _name(name)
{
	return ;
}

Zombie::~Zombie()
{
	std::cout << this->_name << std::endl;
	return ;
}
