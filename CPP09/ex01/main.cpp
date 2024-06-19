#include "RPN.hpp"

int	main(int argc, char *argv[]){
	if (argc != 2)
		std::cout << "Bad input, use the quotation marks for the input" << std::endl;
	try{
		RPN ReversePolishNotation(argv[1]);
	}
	catch(const std::exception& e){}
	
	return 0;
}