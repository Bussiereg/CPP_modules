# include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap(){
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    std::cout << "Constructor default ScavTrap called from " << _name << std::endl;
}

ScavTrap::~ScavTrap(){
    std::cout << "Destructor ScavTrap called from " << _name << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name){
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    std::cout << "Constructor ScavTrap called from " << _name << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const & rhs) : ClapTrap(rhs){
    *this = rhs;
    std::cout << "Copy Constructor ScavTrap called from " << _name << std::endl;
}


ScavTrap & ScavTrap::operator=(ScavTrap const & rhs){
    _hitPoints = rhs._hitPoints;
    _attackDamage = rhs._attackDamage;
    _energyPoints = rhs._energyPoints;
    return *this;
}

void ScavTrap::guardGate(void){
    if (_energyPoints >= 1 && _hitPoints > 0){
        std::cout << "ScavTrap is now in Gate keeper mode!" << std::endl;
        return ;
    }
    std::cout << "ScavTrap " << _name << " is out of energy!" << std::endl;
    return;
}

void ScavTrap::attack(const std::string & target){
    if (_energyPoints >= 1 && _hitPoints > 0){
        std::cout << "ScavTrap " << _name << " attacks ";
        std::cout << target << ", causing " << _attackDamage;
        std::cout << " points of damage" << std::endl;
        _energyPoints -= 1;
        return;
    }
    std::cout << "ScavTrap " << _name << " is out of energy!" << std::endl;
    return;
}