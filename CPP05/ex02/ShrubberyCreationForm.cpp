#include "ShrubberyCreationForm.hpp"
#include <fstream>
// # include <sstream>

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const{
	if (getSignature() == false){
		throw AForm::NoSignature();
	}
	else if (executor.getGrade() > getGradeToExecute()){
		throw Bureaucrat::GradeTooLowException();
	}
    else{
        std::ofstream ofs(this->_target.c_str());
        if (!ofs.is_open()) {
            std::cerr << "Error while creating the file: " << this->_target << std::endl;
        }
        ofs << "       ^" << std::endl;
        ofs << "      / \\" << std::endl;
        ofs << "     /   \\" << std::endl;
        ofs << "    /     \\" << std::endl;
        ofs << "   /       \\" << std::endl;
        ofs << "  /         \\" << std::endl;
        ofs << " /___________\\" << std::endl;
        ofs << "      | |" << std::endl;
        ofs.close();

    }
}

std::string const ShrubberyCreationForm::getTarget(void) const{
    return _target;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target) : AForm("Shubbery", 145, 137), _target(target + "_shrubbery"){

}

ShrubberyCreationForm::ShrubberyCreationForm() : AForm(), _target("default_shrubbery"){
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & rhs) : AForm(rhs), _target(rhs._target){

}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs){
    (void)rhs;
    return *this;
}


ShrubberyCreationForm::~ShrubberyCreationForm(){
}