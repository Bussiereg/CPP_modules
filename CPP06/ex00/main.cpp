#include "ScalarConverter.hpp"

int main(int argc, char **argv){
	if (argc != 2){
		std::cout << "Invalid number of arguments" << std::endl;
		return 1;
	}
	(void)argv;
	std::string arg = argv[1];
	ScalarConverter::convert(arg);
	return 0;
}
