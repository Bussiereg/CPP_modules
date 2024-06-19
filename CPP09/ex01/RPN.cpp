#include "RPN.hpp"



void RPN::_doOperation(char c){
	int el1, el2;

	if (_result.size() < 2){
		std::cout << "Error" << std::endl;
		throw std::exception();
	}
	switch (c)
	{
	case '+':
		el1 = _result.top();
		_result.pop();
		el2 = _result.top();
		_result.pop();
		_result.push(el2 + el1);
		break;
	case '-':
		el1 = _result.top();
		_result.pop();
		el2 = _result.top();
		_result.pop();
		_result.push(el2 - el1);
		break;
	case '/':
		el1 = _result.top();
		_result.pop();
		el2 = _result.top();
		_result.pop();
		_result.push(el2 / el1);
		break;
	case '*':
		el1 = _result.top();
		_result.pop();
		el2 = _result.top();
		_result.pop();
		_result.push(el2 * el1);
		break;
	default:
		break;
	}

}

RPN::RPN(std::string input){
	for (unsigned long i = 0; i < input.size(); i++){
		if (std::isdigit(input[i]))
			_result.push(input[i] -'0');
		else if (input[i] == ' ')
			continue;
		else if (input[i] == '+' ||input[i] == '*' || input[i] == '-' || input[i] == '/' )
			_doOperation(input[i]);
		else{
			std::cout << "Error" << std::endl;
			throw std::exception();
		}
	}
	if (_result.size() != 1){
		std::cout << "Error" << std::endl;
		throw std::exception();
	}
	std::cout << _result.top() << std::endl;
}

RPN::RPN(RPN const & rhs){
	if (this != &rhs)
		*this = rhs;
}

RPN & RPN::operator=(RPN const & rhs){
	_result = rhs._result;
	return *this;
}

RPN::RPN(){
	std::cout << "You can't instiate with this constructor." << std::endl;
}

RPN::~RPN(){
}