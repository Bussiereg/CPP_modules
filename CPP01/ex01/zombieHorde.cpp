#include "Zombie.hpp"

void	Zombie::setname(std::string name){
	this->_name = name;
}

Zombie* zombieHorde( int N, std::string name )
{
    Zombie *zombieHorde1 = new Zombie[N];

	for (int i = 0; i < N; i++){
		zombieHorde1[i].setname(name);
	}
	return (zombieHorde1);
}