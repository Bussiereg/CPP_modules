#include "MutantStack.hpp"

int main()
{
	// TEST 1
	std::cout << "---TEST1---" << std::endl;
	MutantStack<int>	mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();

	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);

	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);

	// TEST 2
	std::cout << "---TEST2---" << std::endl;
	std::deque<int>	mstack2;
	mstack2.push_back(5);
	mstack2.push_back(17);
	std::cout << mstack2.back() << std::endl;
	mstack2.erase(--mstack2.end());

	std::cout << mstack2.size() << std::endl;
	mstack2.push_back(3);
	mstack2.push_back(5);
	mstack2.push_back(737);

	mstack2.push_back(0);
	std::deque<int>::iterator it2 = mstack2.begin();
	std::deque<int>::iterator ite2 = mstack2.end();
	++it2;
	--it2;
	while (it2 != ite2)
	{
		std::cout << *it2 << std::endl;
		++it2;
	}
	std::deque<int> s1(mstack2);
	
	// TEST3
	std::cout << "---TEST3---" << std::endl;
	MutantStack<int>	mstack3;
	mstack3.push(5);
	mstack3.push(17);
	mstack3.pop();
	mstack3.push(3);
	mstack3.push(5);
	mstack3.push(737);
	mstack3.push(0);
	MutantStack<int>::reverse_iterator rit3 = mstack3.rbegin();
	for (rit3 = mstack3.rbegin(); rit3 != mstack3.rend(); ++rit3 ){
		std::cout << *rit3 << std::endl;
	}
	std::stack<int> s3(mstack3);
	return 0;
}