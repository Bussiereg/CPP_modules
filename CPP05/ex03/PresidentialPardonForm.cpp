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

PresidentialPardonForm::PresidentialPardonForm() : AForm(), _target("default_shrubbery"){
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & rhs) : AForm(rhs), _target(rhs._target){

}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs){
    (void)rhs;
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(){
}