#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include <new>

class AAnimal
{
protected:
    std::string type;

public:
    AAnimal();
    AAnimal(AAnimal const & rhs);
    AAnimal & operator=(AAnimal const & rhs);
    virtual ~AAnimal();

    std::string getType(void) const;

    virtual void makeSound(void) const = 0;
};

#endif