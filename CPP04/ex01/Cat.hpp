#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"
# include <iostream>
# include <new>

class Cat : public Animal
{
private:
    Brain *catBrain;
public:
    Cat();
    Cat(Cat const & rhs);
    Cat & operator=(Cat const & rhs);
    ~Cat();

    void makeSound(void) const;
    std::string * getIdeas(void);
};


#endif