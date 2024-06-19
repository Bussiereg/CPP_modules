#include "Harl.hpp"

int main(int argc, char **argv){

	if (argc == 2){
		Harl human(argv[1]);	
		human.complain("DEBUG");
		human.complain("INFO");
		human.complain("WARNING");
		human.complain("ERROR");
		human.complain("ERRazeORqqsd");
		return 0;
	}
	return 1;
}