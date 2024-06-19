#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(int argc, char **argv){
    (void)argv;

    if (argc != 1){
        std::cout << "No arguments please" << std::endl;
        return 1;
    }
    FragTrap ct1;
    FragTrap ct2(ct1);
    FragTrap ct3("Mario");
    ct2.attack("Mario");
    ct2.takeDamage(9);
    ct2.highFiveGuys();
    for (int i = 0; i < 20; i++){
        ct2.beRepaired(1);
    }
    ct2.takeDamage(99);
    ct2.takeDamage(80); 
    return 0;
}