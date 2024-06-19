#include "Bureaucrat.hpp"

std::string const Bureaucrat::getName(void) const{
	return _name;
}

int Bureaucrat::getGrade(void) const{
	return _grade;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & rhs){
	std::cout << "Overload assigment Bureaucrat called" << std::endl;
	if (&rhs != this){
		_grade = rhs._grade;
	}
	return *this;
}

Bureaucrat::Bureaucrat(Bureaucrat const & rhs) : _name(rhs._name), _grade(rhs._grade){
	std::cout << "Copy constructor Bureaucrat called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name), _grade(grade){
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(void) : _name("Yoan"), _grade(150)
{
}

Bureaucrat::~Bureaucrat()
{
}

std::ostream & operator<<(std::ostream & o, Bureaucrat const & rhs){
    o << rhs.getName() << " bureaucrat grade " << rhs.getGrade() << std::endl;
    return o;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade too low";
}

void    Bureaucrat::incrementGrade(void) {
    if ( _grade - 1 < 1 ){
        throw Bureaucrat::GradeTooHighException();
	}
    _grade--;
}

void    Bureaucrat::decrementGrade(void) {
    if ( _grade + 1 > 150 ){
        throw Bureaucrat::GradeTooLowException();
	}
    _grade++;
}
