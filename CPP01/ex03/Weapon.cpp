#include "Weapon.hpp"

std::string const & Weapon::getType(void)
{
	return(this->_type);
}

void	Weapon::setType(std::string type)
{
	this->_type = type;
}

Weapon::Weapon(std::string weapon)
{
	this->setType(weapon);
}

Weapon::~Weapon()
{
}