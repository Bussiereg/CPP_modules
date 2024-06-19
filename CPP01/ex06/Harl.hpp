#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

class Harl
{
private:
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );
	int _limit;
	void (Harl::*_ptr[4])();
	std::string _comp[4];
	void _displayComplain (int lev, std::string comp);
public:
	Harl(std::string levels);
	~Harl();
	void complain( std::string level );
};

#endif