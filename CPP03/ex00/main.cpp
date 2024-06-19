#include "ClapTrap.hpp"

int main(int argc, char **argv){
    (void)argv;

    if (argc != 1){
        std::cout << "No arguments please" << std::endl;
        return 1;
    }
    ClapTrap ct1;
    ClapTrap ct2("Mario");
    ClapTrap ct3(ct1);
    ct1.attack("luigi");
    ct1.takeDamage(9);
    for (int i = 0; i < 11; i++){
        ct1.beRepaired(1);
    }
    ct1.takeDamage(9);
    ct1.takeDamage(9); 
    return 0;
}