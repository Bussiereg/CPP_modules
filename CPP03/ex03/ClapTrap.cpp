#include "ClapTrap.hpp"

unsigned int ClapTrap::getHitPoint(void) const{
    return this->_hitPoints;
}

unsigned int ClapTrap::getEnergyPoint(void) const{
    return this->_energyPoints;
}

unsigned int ClapTrap::getAttackDamage(void) const{
    return this->_attackDamage;
}

void ClapTrap::attack(const std::string & target){
    if (_energyPoints >= 1 && _hitPoints > 0){
        std::cout << "ClapTrap " << _name << " attacks ";
        std::cout << target << ", causing " << _attackDamage;
        std::cout << " points of damage" << std::endl;
        _energyPoints -= 1;
        return;
    }
    std::cout << "ClapTrap " << _name << " is out of energy!" << std::endl;
    return;
}

void ClapTrap::takeDamage(unsigned int amount){
    if (_hitPoints <= amount)
    {
        _hitPoints = 0;
        std::cout << "ClapTrap " << _name << " takes " << amount << " damages!" << std::endl;
        std::cout << "ClapTrap " << _name << " is dead!" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << _name << " takes " << amount << " damages!" << std::endl;
    _hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount){
    if (_energyPoints >= 1 && _hitPoints > 0){
        std::cout << "ClapTrap " << _name << " repairs itself with ";
        std::cout << amount << " point(s)" << std::endl;
        _hitPoints += amount;
        _energyPoints -= 1;
        return;
    }
    std::cout << "ClapTrap " << _name << " is out of energy!" << std::endl;
    return;
}

ClapTrap & ClapTrap::operator=(ClapTrap const & rhs)
{
    _name = rhs._name;
    _hitPoints = rhs._hitPoints;
    _energyPoints = rhs._energyPoints;
    _attackDamage = rhs._attackDamage;
    return *this;
}

ClapTrap::ClapTrap() : _name("WALL.E"), _hitPoints(10), _energyPoints(10), _attackDamage(0){
    std::cout << "Constructor default ClapTrap called from " << _name << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "Constructor ClapTrap called from " << _name << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & rhs){
    *this = rhs;
    std::cout << "Copy Constructor ClapTrap called from " << _name << std::endl;
}

ClapTrap::~ClapTrap(){
    std::cout << "Destructor ClapTrap called from " << _name << std::endl;
}