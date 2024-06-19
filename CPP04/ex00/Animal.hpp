#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <new>

class Animal
{
protected:
    std::string type;
public:
    Animal();
    Animal(Animal const & rhs);
    Animal & operator=(Animal const & rhs);
    virtual ~Animal();

    virtual void makeSound(void) const;
    std::string getType(void) const;
};


#endif