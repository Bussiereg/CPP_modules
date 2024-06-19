#include "Span.hpp"

void Span::addNumber(int rhs){
	if (_inventory.size() + 1 > _nbElements)
		throw Span::InventoryFull();
	this->_inventory.push_back(rhs);
}

void Span::addNumber(std::deque<int>::const_iterator iteStart, std::deque<int>::const_iterator iteEnd){
	if (iteEnd - iteStart  + _inventory.size() > _nbElements){
		throw Span::InventoryFull();
	}
	this->_inventory.insert(_inventory.end(), iteStart, iteEnd);
}

int Span::shortestSpan(void) {
	if (_inventory.size() == 0)
		throw Span::noNbStored();
	else if (_inventory.size() == 1)
		throw Span::oneNbStored();

    std::sort(_inventory.begin(), _inventory.end());

    int minimum = __INT_MAX__;
    for (size_t i = 1; i < _inventory.size(); ++i) {
        int diff = std::abs(_inventory[i] - _inventory[i - 1]);
        if (diff < minimum)
            minimum = diff;
    }
    return minimum;
}

int Span::longestSpan(void){
	if (_inventory.size() == 0)
		throw Span::noNbStored();
	else if (_inventory.size() == 1)
		throw Span::oneNbStored();
	return (*std::max_element(_inventory.begin(), _inventory.end()) - *std::min_element(_inventory.begin(), _inventory.end()));
}


const char* Span::InventoryFull::what() const throw() {
    return "the inventory if full";
}

const char* Span::noNbStored::what() const throw() {
    return "No span can be found: No numbers are stored";
}

const char* Span::oneNbStored::what() const throw() {
    return "No span can be found: One number is stored";
}

Span::Span(Span const & rhs){
	*this = rhs;
}

Span & Span::operator=(Span const & rhs){
	if ( this != &rhs ){
		_nbElements = rhs._nbElements;
		_inventory = rhs._inventory;
	}
	return *this;
}

Span::Span() :  _nbElements(0){
}

Span::Span(unsigned int N) :  _nbElements(N){
}

Span::~Span(){
}

std::deque<int> & Span::getList(){
	return (_inventory);
}

std::deque<int> & Span::getInventory(void){
	return (_inventory);
}