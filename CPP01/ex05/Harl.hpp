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
	void (Harl::*_ptr[4])();
	std::string _comp[4];
public:
	Harl();
	~Harl();
	void complain( std::string level );
};

#endif