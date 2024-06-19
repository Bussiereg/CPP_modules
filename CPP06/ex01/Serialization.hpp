#ifndef SERIALIZATION_HPP
# define SERIALIZATION_HPP

# include <iostream>

typedef unsigned long int	uintptr_t;

typedef struct{
	std::string code;
	std::string username;
} Data; 

class Serialization
{
private:
	Serialization();
public:
	Serialization(Serialization const & rhs);
	Serialization & operator=(Serialization const & rhs);
	~Serialization();

	static uintptr_t serialize(Data * ptr);
	static Data* deserialize(uintptr_t raw); 
};

#endif