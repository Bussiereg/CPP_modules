#include <iostream>

int main(int argc, char **argv){
	if (argc == 1){
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	}
	else{
		for (int j = 1; j != argc; j++){
			std::string str = argv[j];
			for (long unsigned int i = 0; i < str.length(); i++) {
				char buf = toupper(str[i]);
				std::cout << buf;
			}
		}
	}
	std::cout << std::endl;
	return 0;
}