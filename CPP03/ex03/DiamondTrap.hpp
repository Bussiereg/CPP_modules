#ifndef DIAMOND_HPP
# define DIAMOND_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"
# include "ClapTrap.hpp"
# include <iostream>

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
    std::string   _name;
public:    
    DiamondTrap();
    DiamondTrap(std::string name);
    DiamondTrap(DiamondTrap const & rhs);
    DiamondTrap & operator=(DiamondTrap const & rhs);
    ~DiamondTrap();

	void attack(const std::string & target);
    void whoAmI();
};


#endif