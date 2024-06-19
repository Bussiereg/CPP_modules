#include "Zombie.hpp"

int main(){
	Zombie *bob = newZombie("Bob");
	bob->announce();
	randomChump("Brainy");
	delete bob;
	return 0;
}