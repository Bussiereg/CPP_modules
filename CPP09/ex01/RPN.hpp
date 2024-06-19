#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>
#include <algorithm>

class RPN
{
private:
	void _doOperation(char c);
	std::stack<int> _result;
	RPN();
	RPN(RPN const & rhs);
	RPN & operator=(RPN const & rhs);

public:
	RPN(std::string rhs);
	~RPN();
};

#endif