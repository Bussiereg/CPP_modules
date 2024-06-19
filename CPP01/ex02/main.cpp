#include <iostream>

int main(){
	std::string stringVAL = "HI THIS IS BRAIN";
	std::string *stringPTR = &stringVAL;
	std::string& stringREF= stringVAL;

	std::cout << "The memory address of stringVAL is :" << &stringVAL << std::endl;
	std::cout << "The memory address of stringPTR is :" << stringPTR << std::endl;
	std::cout << "The memory address of stringREG is :" << &stringREF << std::endl;

	std::cout << "The value of stringVAL is            :" << stringVAL << std::endl;
	std::cout << "The value pointed to by stringPTR is :" << *stringPTR << std::endl;
	std::cout << "The value pointed to by stringREG is :" << stringREF << std::endl;
	return 0;
}