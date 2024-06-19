#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <new>

class Bureaucrat
{
private:
	std::string const _name;
	int _grade;
public:
	Bureaucrat();
	Bureaucrat(Bureaucrat const & rhs);
	Bureaucrat(std::string const name, int grade);
	Bureaucrat & operator=(Bureaucrat const & rhs);
	~Bureaucrat();

	std::string const getName(void) const;
	int getGrade(void) const;
	void    incrementGrade(void);
	void    decrementGrade(void);

    class GradeTooHighException : public std::exception {
        public:
            virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
        public:
            virtual const char* what() const throw();
    };

};

std::ostream & operator<<(std::ostream & o, Bureaucrat	 const & rhs);

#endif