#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"
# include <iostream>
# include <new>

class WrongCat : public WrongAnimal
{
private:

public:
	WrongCat();
    WrongCat(WrongCat const & rhs);
    WrongCat & operator=(WrongCat const & rhs);
    ~WrongCat();

    void makeSound(void) const;
};

#endif