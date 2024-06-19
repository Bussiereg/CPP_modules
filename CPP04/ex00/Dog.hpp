#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include <iostream>
# include <new>

class Dog : public Animal
{
private:

public:
    Dog();
    Dog(Dog const & rhs);
    Dog & operator=(Dog const & rhs);
    ~Dog();

    void makeSound(void) const;
};


#endif