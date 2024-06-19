#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap(){
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    std::cout << "Constructor default FragTrap called from " << _name << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name){
    std::cout << "Constructor FragTrap called from " << _name << std::endl;
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
}

FragTrap::~FragTrap(){
    std::cout << "Destructor FragTrap called from " << _name << std::endl;	
}

FragTrap::FragTrap(FragTrap const & rhs) : ClapTrap(rhs){
    *this = rhs;
    std::cout << "Copy Constructor FragTrap called from " << _name << std::endl;
}

FragTrap & FragTrap::operator=(FragTrap const & rhs){
    _name = rhs._name;
    _hitPoints = rhs._hitPoints;
    _attackDamage = rhs._attackDamage;
    _energyPoints = rhs._energyPoints;
    return *this;
}

void FragTrap::attack(const std::string & target){
    if (_energyPoints >= 1 && _hitPoints > 0){
        std::cout << "FragTrap " << _name << " attacks ";
        std::cout << target << ", causing " << _attackDamage;
        std::cout << " points of damage" << std::endl;
        _energyPoints -= 1;
        return;
    }
    std::cout << "FragTrap " << _name << " is out of energy!" << std::endl;
    return;
}

void FragTrap::highFiveGuys(void){
    if (_energyPoints >= 1 && _hitPoints > 0){
        std::cout << "FragTrap " << _name << " executes a tricky High fives with an ennemy, which has been positively accepted." << std::endl;
        return ;
    }
    std::cout << "FragTrap " << _name << " is out of energy!" << std::endl;
    return;
}