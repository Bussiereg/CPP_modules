#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"
# include <iostream>

class Dog : public AAnimal
{
private:
    Brain *dogBrain;
public:
    Dog();
    Dog(Dog const & rhs);
    Dog & operator=(Dog const & rhs);
    ~Dog();

    void makeSound(void) const;
    std::string * getIdeas(void);
};


#endif