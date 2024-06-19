#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
private:
	std::string ideas[100];
public:
	Brain();
	Brain(Brain const & rhs);
	Brain & operator=(Brain const & rhs);
	~Brain();

	std::string *getIdeas(void);
};

#endif