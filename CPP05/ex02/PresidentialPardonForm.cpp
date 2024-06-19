#include "PresidentialPardonForm.hpp"

void PresidentialPardonForm::execute(Bureaucrat const & executor) const{
	if (executor.getGrade() > getGradeToExecute()){
		throw AForm::GradeTooLowException();
	}
	else if (getSignature() == false){
		throw AForm::NoSignature();
	}
	else{
		std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	}
}

std::string const PresidentialPardonForm::getTarget(void) const{
    return _target;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const & target) : AForm("presidential pardon", 25, 5), _target(target){
}

PresidentialPardonForm::PresidentialPardonForm() : AForm(), _target("presidential pardon"){
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & rhs) : AForm(rhs), _target(rhs._target){
	std::cout << "copy constructor called" << std::endl;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs){
	std::cout << "operator= called" << std::endl;
    (void)rhs;
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(){
}