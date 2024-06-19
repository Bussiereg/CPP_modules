#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>

class ScavTrap : virtual public ClapTrap
{
private:

public:
    ScavTrap();
    ScavTrap(std::string name);
    ScavTrap(ScavTrap const & rhs);
    ScavTrap & operator=(ScavTrap const & rhs);
    ~ScavTrap();

	void attack(const std::string & target);
    void guardGate(void);
};


#endif