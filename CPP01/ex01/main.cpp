#include "Zombie.hpp"

int main(){
	int N = 10;
	Zombie *horde = zombieHorde(N, "Brainy");

	for (int i = 0; i < N; i++){
		horde[i].announce();
	}

	delete [] horde;
	return 0;
}