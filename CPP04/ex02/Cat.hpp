#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"
# include <iostream>
# include <new>

class Cat : public AAnimal
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