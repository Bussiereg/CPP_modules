#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap(), _name("WALL.E"){
    ClapTrap::_name = "WALL.E_clap_name";
    _energyPoints = 50;
    std::cout << "Constructor default DiamondTrap called from " << _name << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name){
    _energyPoints = 50;
    std::cout << "Constructor DiamondTrap called from " << _name << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const & rhs) : ClapTrap(rhs), ScavTrap(rhs), FragTrap(rhs){
    *this = rhs;
    std::cout << "Copy Constructor DiamondTrap called from " << _name << std::endl;
}

DiamondTrap & DiamondTrap::operator=(DiamondTrap const & rhs){
    _name = rhs._name;
    _hitPoints = rhs._hitPoints;
    _attackDamage = rhs._attackDamage;
    _energyPoints = rhs._energyPoints;
    return *this;
}

DiamondTrap::~DiamondTrap(){
    std::cout << "Destructor DiamondTrap called from " << _name << std::endl;
}

void DiamondTrap::attack(const std::string & target){
    ScavTrap::attack(target);
}


void DiamondTrap::whoAmI(){
    std::cout << "My name is " << _name << " and my ClapTrap name is " << ClapTrap::_name << std::endl;
}