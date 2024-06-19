#include "ScavTrap.hpp"

int main(int argc, char **argv){
    (void)argv;

    if (argc != 1){
        std::cout << "No arguments please" << std::endl;
        return 1;
    }
    ScavTrap ct1;
    ScavTrap ct2(ct1);
    ScavTrap ct3("Mario");
    ct1.attack("luigi");
    ct1.takeDamage(9);
    ct1.guardGate();
    for (int i = 0; i < 11; i++){
        ct1.beRepaired(1);
    }
    ct1.takeDamage(9);
    ct1.takeDamage(9); 
    return 0;
}