#include "Bureaucrat.hpp"

int main(){
	try	{
		std::cout << "---Test1---" << std::endl;
		Bureaucrat martin("Martin", 10);
		std::cout << martin;
		std::cout << "---Test2---" << std::endl;
		Bureaucrat bobby = martin;
		bobby.decrementGrade();
		std::cout << bobby;
		std::cout << "---Test3---" << std::endl;
		Bureaucrat JohnDoe;
		std::cout << JohnDoe;
	}
	catch(const std::exception& e)	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "---Test4---" << std::endl;
	try	{
		Bureaucrat martin("Martin", -10);
	}
	catch(const std::exception& e)	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "---Test5---" << std::endl;
	try	{
		Bureaucrat martin("Martin", 1000);
	}
	catch(const std::exception& e)	{
		std::cerr << e.what() << std::endl;
	}
	
	return 0;
}