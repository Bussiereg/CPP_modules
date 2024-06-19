#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include <iostream>
# include <new>

class Intern
{
private:
    std::string _formType[3];
public:
    Intern();
    Intern(Intern const & rhs);
    ~Intern();
    Intern & operator=(Intern const & rhs);
    AForm * makeForm(std::string formName, std::string target);
    
    class unknownForm : public std::exception {
        public:
            virtual const char* what() const throw();
    };
};

#endif