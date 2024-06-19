#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <cstdlib>
# include <iostream>
# include <new>

class RobotomyRequestForm : public AForm
{
private:
    std::string const _target;
public:
    RobotomyRequestForm();
    RobotomyRequestForm(std::string const & target);
    RobotomyRequestForm(RobotomyRequestForm const & rhs);
    RobotomyRequestForm & operator=(RobotomyRequestForm const & rhs);
    ~RobotomyRequestForm();

    void execute(Bureaucrat const & executor) const;

    std::string const getTarget(void) const;
};


#endif