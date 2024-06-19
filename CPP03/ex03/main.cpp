#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"

int main(int argc, char **argv){
    (void)argv;

    if (argc != 1){
        std::cout << "No arguments please" << std::endl;
        return 1;
    }
    DiamondTrap ct3;
    DiamondTrap ct4(ct3);
    DiamondTrap ct5("Bobby");
    // ct3.attack("Luigi");
    // ct3.attack("Waluigi");
    ct3.highFiveGuys();
    ct3.whoAmI();
    ct4.whoAmI();
    ct5.highFiveGuys();
    std::cout << "Energy point is: " << ct3.getEnergyPoint() << std::endl;
    std::cout << "attack point is: " << ct3.getAttackDamage() << std::endl;
    std::cout << "Hit point is: " << ct3.getHitPoint() << std::endl;
    return 0;
}