#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <list>
#include <vector>

class Span
{
private:
	Span();
	unsigned int _nbElements;
	std::deque<int> _inventory;
public:
	Span(unsigned int N);	
	Span(Span const & rhs);
	Span & operator=(Span const & rhs);
	~Span();

    std::deque<int> & getInventory(void);
	void addNumber(int rhs);
	void addNumber(std::deque<int>::const_iterator iteStart, std::deque<int>::const_iterator iteEnd);
	int shortestSpan(void);
	int longestSpan(void);
    std::deque<int> & getList();

    class InventoryFull : public std::exception {
        public:
            virtual const char* what() const throw();
    };

    class noNbStored : public std::exception {
        public:
            virtual const char* what() const throw();
    };
    class oneNbStored : public std::exception {
        public:
            virtual const char* what() const throw();
    };


};

#endif