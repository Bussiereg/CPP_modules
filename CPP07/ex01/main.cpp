#include "iter.hpp"

void printUppercase(std::string & str){
    const char * str_c = str.c_str();
    for (long unsigned int i = 0; i < str.length(); i++){
        if (str_c[i] >= 97 && str_c[i] <= 122 )
            std::cout << static_cast<char>(str_c[i] - (97 - 65));
        else
            std::cout << str_c[i];
    }
     std::cout << std::endl;
}

void printNb(int & nb){
    std::cout << nb << std::endl;
}


int main( void ) {
    int intTab[] = {1, 2, 3, 4, 5};
    std::string stringTab[] = {"hello", "bonjour", "apple"};
    std::cout << "---Test 1---" << std::endl;
    iter(intTab, 5, &printNb);
    std::cout << "---Test 2---" << std::endl;
    iter(stringTab, 3, &printUppercase);
    return 0;
}
