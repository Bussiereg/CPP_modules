#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(ScalarConverter const & rhs){
    (void)rhs;
    return ;
}

ScalarConverter & ScalarConverter::operator=(ScalarConverter const & rhs){
    if ( this != &rhs )
    	(void)rhs;
    return *this;
}

ScalarConverter::ScalarConverter(){
    return;
}

ScalarConverter::~ScalarConverter(){
    return;
}

void ScalarConverter::convert(std::string & arg){
	char _c = 0;
	int _i = 0;
	float _f = 0.0f;
	double _d = 0.0;
	
	std::string typeTab[5] = {"CHAR", "INT", "FLOAT", "DOUBLE", "NONE"};
	std::string type = "UNKNOWN";

	int dot = 0;
	int flagFloat = 0;
	int exp = 0;
	for (unsigned long i = 0; i < arg.length(); i++){
		if (!std::isdigit(arg[i])){
			if (arg[i] == '.')
				dot++;
			else if ((arg[i] == '-' || arg[i] == '+') && i == 0)
				continue;
			else if ((arg[i] == '-' || arg[i] == '+') && (arg[i - 1] == 'e' || arg[i - 1] == 'E'))
				continue;
			else if (arg[i] == 'f' || arg[i] == 'F')
				flagFloat++;
			else if (arg[i] == 'e' || arg[i] == 'E')
				exp++;
			else{
				type = "NONE";
                break;
            }
		}
	}
	if (dot > 1 || flagFloat > 1 || exp > 1 || arg == "f" || arg == "F" || arg == "e" || arg == "E" || arg == ".")
		type = "NONE";
    else if (type == "UNKNOWN"){
	    double result = atof(arg.c_str());
        if ( result >= -128 && result <= 127 && !flagFloat && !dot)
            type = "CHAR";
        else if ( result >= INT_MIN && result <= INT_MAX && !flagFloat && !dot)
            type = "INT";
        else if ( result >= -FLT_MAX && result <= FLT_MAX && flagFloat)
            type = "FLOAT";
        else
            type = "DOUBLE";
    }

	int var = 0;
	while (var < 5){
		if (typeTab[var++] == type)
			break;
	}
	switch (var){
	case 1:
		_c = static_cast<char>(atoi(arg.c_str()));
		_i = static_cast<int>(_c);
		_f = static_cast<float>(_c);
		_d = static_cast<double>(_c);
		break;
	case 2:
		_i = static_cast<int>(atoi(arg.c_str()));
		_c = static_cast<char>(_i);
		_d = static_cast<double>(_i);
		_f = static_cast<float>(_i);
		break;
	case 3:
		_f = static_cast<float>(atof(arg.c_str()));
		_c = static_cast<char>(_f);
		_i = static_cast<int>(_f);
		_d = static_cast<double>(_f);
		break;
	case 4:
		_d = atof(arg.c_str());
		_f = static_cast<float>(_d);
		_c = static_cast<char>(_d);
		_i = static_cast<int>(_d);
		break;
	default:
        if (arg == "inf" || arg =="inff"){
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: +inff" << std::endl;
            std::cout << "double: +inf" << std::endl;
        }
        else if (arg == "-inf" || arg =="-inff"){
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: -inff" << std::endl;
            std::cout << "double: -inf" << std::endl;
        }
        else{
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: nanf" << std::endl;
            std::cout << "double: nan" << std::endl;
        }
        exit(0);
	}
	std::cout << "char: ";
	if ((_i > 127 || _i < -128))
		std::cout << "impossible" << std::endl;
	else if ((_i >= 32 && _i <= 126))
		std::cout << "'" <<  _c << "'" << std::endl;
	else if (_i < 32 || _i >= 127)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "impossible" << std::endl;
	std::cout << "int: ";
	if (_d < INT_MIN || _d > INT_MAX)
		std::cout << "Impossible" << std::endl;
	else
		std::cout << _i << std::endl;
	std::cout << "float: " << _f;
	if ((_f == static_cast<int>(_f)) && (_f > -1000000 && _f < 1000000))
		std::cout << ".0f" << std::endl;
	else
		std::cout << "f" << std::endl;
	std::cout << "double: " << _d;
	if ((_d == static_cast<int>(_d)) && (_d > -1000000 && _d < 1000000))
		std::cout << ".0";
	std::cout << std::endl;
}