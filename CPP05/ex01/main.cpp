#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(){
	std::cout << "---Test1---" << std::endl;
    try {
        Bureaucrat martin("Martin", 9);
        Form form("28B", 10, 10);
        martin.signForm(form);
        std::cout << std::endl << std::endl << form << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    
	std::cout << "---Test2---" << std::endl;
    try {
        Bureaucrat bobby("Bobby", 15);
        Form form("28B", 10, 10);
        bobby.signForm(form);
        std::cout << std::endl << std::endl << form << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}