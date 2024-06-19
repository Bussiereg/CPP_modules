#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include <iostream>
# include <new>

class Cat : public Animal
{
private:

public:
    Cat();
    Cat(Cat const & rhs);
    Cat & operator=(Cat const & rhs);
    ~Cat();

    void makeSound(void) const;
};


#endif