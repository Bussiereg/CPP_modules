#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <iostream>
# include <new>

class ShrubberyCreationForm : public AForm
{
private:
    std::string const _target;
public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string const & target);
    ShrubberyCreationForm(ShrubberyCreationForm const & rhs);
    ShrubberyCreationForm & operator=(ShrubberyCreationForm const & rhs);
    ~ShrubberyCreationForm();

    void execute(Bureaucrat const & executor) const;

    std::string const getTarget(void) const;
};


#endif