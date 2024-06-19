#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(): _name("49.3"), _signature(false), _gradeToSign(1), _gradeToExecute(1){
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _signature(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute){
    if (_gradeToSign < 1 || _gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    else if (_gradeToSign > 150 || _gradeToExecute > 150)
        throw AForm::GradeTooLowException();
}

AForm & AForm::operator=(AForm const & rhs){
    _signature = rhs._signature;
    return *this;
}

AForm::AForm(AForm const & rhs) : _name(rhs._name), _signature(rhs._signature), _gradeToSign(rhs._gradeToSign), _gradeToExecute(rhs._gradeToExecute){
}

AForm::~AForm(){
}

std::ostream & operator<<(std::ostream & o, AForm & rhs){
    o << "---------Form status---------" << std::endl;
    o << "Form name: " << rhs.getName() << std::endl;
    o << "Signature status: " << rhs.getSignature() << std::endl;
    o << "Grade requirement to sign " << rhs.getGradeToSign() << std::endl;
    o << "Grade requirement to execute " << rhs.getGradeToExecute() << std::endl;
    return o;
}

std::string AForm::getName(void) const{
    return _name;
}

bool AForm::getSignature(void) const{
    return _signature;
}

int AForm::getGradeToSign(void) const{
    return _gradeToSign;
}

int AForm::getGradeToExecute(void) const{
    return _gradeToExecute;
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade too low";
}

const char* AForm::NoSignature::what() const throw() {
    return "Signature required";
}

void AForm::beSigned(Bureaucrat const & rhs){
    if (rhs.getGrade() > _gradeToSign){
        throw AForm::GradeTooLowException();
    }
    else{
        _signature = true;
    }
}