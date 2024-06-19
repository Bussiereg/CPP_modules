#include "RobotomyRequestForm.hpp"

std::string const RobotomyRequestForm::getTarget(void) const{
    return _target;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const & target) : AForm("robotomy request", 72, 45), _target(target){

}

RobotomyRequestForm::RobotomyRequestForm() : AForm(), _target("default_shrubbery"){
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & rhs) : AForm(rhs), _target(rhs._target){

}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs){
    (void)rhs;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(){
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const{
	if (executor.getGrade() > getGradeToExecute()){
		throw AForm::GradeTooLowException();
	}
	else if (getSignature() == false){
		throw AForm::NoSignature();
	}
	else{
		static int i = 0;
		i++;
		if (i % 2 == 0){
			std::cout << "DRRRR...DRRRRR..DRRRRR..";
			std::cout << _target << " has been robotomized" << std::endl;
		}
		else{
			std::cout << "The robotomy failed" << std::endl;
		}
	}
}