#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"
# include <iostream>
# include <new>

class PresidentialPardonForm : public AForm
{
private:
    std::string const _target;
public:
    PresidentialPardonForm();
    PresidentialPardonForm(std::string const & target);
    PresidentialPardonForm(PresidentialPardonForm const & rhs);
    PresidentialPardonForm & operator=(PresidentialPardonForm const & rhs);
    ~PresidentialPardonForm();
    
    void execute(Bureaucrat const & executor) const;

    std::string const getTarget(void) const;
};

#endif