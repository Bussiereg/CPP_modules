#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <new>

class WrongAnimal
{
protected:
    std::string type;
public:
	WrongAnimal();
    WrongAnimal(WrongAnimal const & rhs);
    WrongAnimal & operator=(WrongAnimal const & rhs);
    virtual ~WrongAnimal();

    void makeSound(void) const;
    std::string getType(void) const;
};

#endif