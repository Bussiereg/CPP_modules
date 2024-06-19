#include "Bureaucrat.hpp"
#include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

int main(){
    Bureaucrat ash("ash", 149);
    Bureaucrat martin("martin", 2);
    ShrubberyCreationForm form1("Shrubbery");
    RobotomyRequestForm form2("Robotomy");
    PresidentialPardonForm form3("President");

    std::cout << "\n--------------- Form 1 ( Shrubbery ) ---------------" << std::endl;
    try{
        std::cout <<  std::endl << form1 << std::endl;
        ash.signForm(form1);
        ash.executeForm(form1);
        martin.signForm(form1);
        ash.executeForm(form1);
        martin.executeForm(form1);
        std::cout <<  std::endl << form1 << std::endl;
    } catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n--------------- Form 2 ( Robotomy ) ---------------" << std::endl;
    try{
        std::cout <<  std::endl << form2 << std::endl;
        ash.signForm(form2);
        ash.executeForm(form2);
        martin.signForm(form2);
        ash.executeForm(form2);
        form2.execute(martin);
        form2.execute(martin);
        std::cout <<  std::endl << form2 << std::endl;
    }
    catch(const std::exception& e){
        std::cerr << e.what() << '\n';
    }

    std::cout << "\n--------------- Form 3 ( President ) ---------------" << std::endl;
    try{
        std::cout <<  std::endl << form3 << std::endl;
        ash.signForm(form3);
        ash.executeForm(form3);
        martin.signForm(form3);
        ash.executeForm(form3);
        martin.executeForm(form3);
        std::cout <<  std::endl << form3 << std::endl;
    }
    catch(const std::exception& e){
        std::cerr << e.what() << '\n';
    }
    return 0;
}