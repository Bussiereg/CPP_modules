#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(): _name("49.3"), _signature(false), _gradeToSign(1), _gradeToExecute(1){
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _signature(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute){
    if (_gradeToSign < 1 || _gradeToExecute < 1)
        throw Form::GradeTooHighException();
    else if (_gradeToSign > 150 || _gradeToExecute > 150)
        throw Form::GradeTooLowException();
}

Form & Form::operator=(Form const & rhs){
    _signature = rhs._signature;
    return *this;
}

Form::Form(Form const & rhs) : _name(rhs._name), _signature(rhs._signature), _gradeToSign(rhs._gradeToSign), _gradeToExecute(rhs._gradeToExecute){
}

Form::~Form(){
}

std::ostream & operator<<(std::ostream & o, Form & rhs){
    o << "---------Form status---------" << std::endl;
    o << "Form name: " << rhs.getName() << std::endl;
    o << "Signature status: " << rhs.getSignature() << std::endl;
    o << "Grade requirement to sign " << rhs.getGradeToSign() << std::endl;
    o << "Grade requirement to execute " << rhs.getGradeToExecute() << std::endl;
    return o;
}

std::string Form::getName(void){
    return _name;
}

bool Form::getSignature(void){
    return _signature;
}

int Form::getGradeToSign(void){
    return _gradeToSign;
}

int Form::getGradeToExecute(void){
    return _gradeToExecute;
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Grade too high";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Grade too low";
}

void Form::beSigned(Bureaucrat const & rhs){
    if (rhs.getGrade() > _gradeToSign){
        throw Form::GradeTooLowException();
    }
    _signature = true;
}