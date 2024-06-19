#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"
# include <iostream>
# include <new>


class Form
{
private:
    std::string const _name;
    bool _signature;
    int const _gradeToSign;
    int const _gradeToExecute;
public:
    Form();
    Form(Form const & rhs);
    Form(std::string name, int gradeToSign, int gradeToExecute);
    Form & operator=(Form const & rhs);
    ~Form();

    std::string getName(void);
    bool getSignature(void);
    int getGradeToSign(void);
    int getGradeToExecute(void);

    void beSigned(Bureaucrat const & rhs);

    class GradeTooHighException : public std::exception{
        public:
            virtual const char* what() const throw();
    };
    class GradeTooLowException : public std::exception{
        public:
            virtual const char* what() const throw();
    };
};

std::ostream & operator<<(std::ostream & o, Form & rhs);



#endif