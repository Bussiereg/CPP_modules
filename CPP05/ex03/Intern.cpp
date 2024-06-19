#include "Intern.hpp"

AForm * Intern::makeForm(std::string formName, std::string target){
    int index = 0;
    AForm *formIntern = NULL;
    for (int i = 0; i < 3; i++){
        if (formName == _formType[i])
            index = i + 1;
    }
    switch (index)
    {
    case 1:
        formIntern = new RobotomyRequestForm(target);
        std::cout << "Intern creates " << formName << std::endl;
        break;
    case 2:
        formIntern = new PresidentialPardonForm(target);
        std::cout << "Intern creates " << formName << std::endl;
        break;
    case 3:
        formIntern = new ShrubberyCreationForm(target);
        std::cout << "Intern creates " << formName << std::endl;
        break;
    default:
        throw unknownForm();
    }
    return formIntern;

}

Intern::Intern(){
    _formType[0] = "robotomy request";
    _formType[1] = "presidential pardon";
    _formType[2] = "shrubbery creation";
}

Intern::Intern(Intern const & rhs){
    *this = rhs;
}

Intern & Intern::operator=(Intern const & rhs){
    (void)rhs;
    return *this;
}

Intern::~Intern(){
}

const char* Intern::unknownForm::what() const throw() {
    return "This type of form does not exist";
}