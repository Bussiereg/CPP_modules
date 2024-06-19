#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon
{
private:
	std::string _type;
public:
	Weapon(std::string weapon);
	~Weapon();

	std::string const & getType();
	void	setType(std::string type);
};

#endif