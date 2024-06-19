#include "Form.hpp"
#include "Bureaucrat.hpp"

std::string const Bureaucrat::getName(void) const{
	return _name;
}

int Bureaucrat::getGrade(void) const{
	return _grade;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & rhs){
	if (this != &rhs){
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
    return "Out of range error: The Bureaucrat grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Out of range error: The bureaucrat grade is too low";
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

void Bureaucrat::signForm(Form & rhs){
	if (rhs.getSignature() == true){
		std::cout << "Form " << rhs.getName() << " has already been signed" << std::endl;
	}
	else{
		try		{
			rhs.beSigned(*this);
			std::cout << "Bureaucrat " << _name << " signed " << rhs.getName() << std::endl;
		}
		catch(const std::exception& e)		{
			std::cerr << _name << " coulnd't sign " << rhs.getName() << " because " << e.what() << std::endl;
		}
	}
}
