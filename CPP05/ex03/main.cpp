#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(){
    Bureaucrat martin("martin", 2);
    Intern benoit;
    AForm *rff;

    std::cout << "\n--------------- Form 1 ( Robotomy ) ---------------" << std::endl;
    rff = benoit.makeForm("robotomy request", "Denis");
    martin.signForm(*rff);
    martin.executeForm(*rff);
    martin.executeForm(*rff);
    delete rff;

    std::cout << "\n--------------- Form 2 ( Presidential ) ---------------" << std::endl;
    rff = benoit.makeForm("presidential pardon", "Denis");
    martin.signForm(*rff);
    martin.executeForm(*rff);
    delete rff;

    std::cout << "\n--------------- Form 3 ( Shrubbery ) ---------------" << std::endl;
    rff = benoit.makeForm("shrubbery creation", "Denis");
    martin.signForm(*rff);
    martin.executeForm(*rff);
    delete rff;
    
    try
    {
        std::cout << "\n--------------- Form 4 ( Unknown ) ---------------" << std::endl;
        rff = benoit.makeForm("shrasdubbery creation", "Denis");
        martin.signForm(*rff);
        martin.executeForm(*rff);
        delete rff;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}