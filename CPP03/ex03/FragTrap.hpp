#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>

class FragTrap : virtual public ClapTrap
{
private:

public:
	FragTrap();
	FragTrap(std::string name);
    FragTrap(FragTrap const & rhs);
    FragTrap & operator=(FragTrap const & rhs);
	~FragTrap();

	void attack(const std::string & target);
	void highFiveGuys(void);
};

#endif