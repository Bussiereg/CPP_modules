#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"
# include <iostream>
# include <new>


class AForm
{
private:
    std::string const _name;
    bool _signature;
    int const _gradeToSign;
    int const _gradeToExecute;
public:
    AForm();
    AForm(AForm const & rhs);
    AForm(std::string name, int gradeToSign, int gradeToExecute);
    AForm & operator=(AForm const & rhs);
    ~AForm();

    std::string getName(void) const;
    bool getSignature(void) const;
    int getGradeToSign(void) const;
    int getGradeToExecute(void) const;

    void beSigned(Bureaucrat const & rhs);

    virtual void execute(Bureaucrat const & executor) const = 0;

    class GradeTooHighException : public std::exception{
        public:
            virtual const char* what() const throw();
    };
    class GradeTooLowException : public std::exception{
        public:
            virtual const char* what() const throw();
    };
    class NoSignature : public std::exception {
        public:
            virtual const char* what() const throw();
    };
};

std::ostream & operator<<(std::ostream & o, AForm & rhs);



#endif