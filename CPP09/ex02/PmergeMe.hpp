#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <deque>
#include <sstream>
#include <ctime>
#include <sys/time.h>
#include <stdint.h>

#define MAX_UINT 4294967295

typedef struct Pair{
	Pair(unsigned int el1, unsigned int el2) : first(el1), second(el2){
		if (first < second)
			swap();
	}
	unsigned int first;
	unsigned int second;
	void swap(){
		unsigned int temp;
		temp = second;
		second = first;
		first = temp;
	}
	void print(){
		std::cout << first << " - " << second << std::endl;
	}
} t_pair;

template <typename T, template<typename, typename> class Container>
class PmergeMe
{
private:
	Container<T, std::allocator<T> > _input;
	Container<t_pair, std::allocator<t_pair> > _step1;
	Container<T, std::allocator<T> > _mainChain;
	Container<T, std::allocator<T> > _pendNb;
	Container<T, std::allocator<T> > _insertionOrder;
	bool _oddEl;
	void _fordJohnsonAlgo();
	void _createMainAndPendChain();
	void _createPairAndSort();
	void	_printIterationOrder();
	void	_printStep2();
	void	_printStep1();	
	void	_printVector();	
	unsigned int _fordJohnsonTrick( unsigned int elToInsert);
	void _createInsertionOrder();	
	void _parseInput(int argc, char **argv);
	bool _isUInteger(const std::string& s);
	static bool _compareFirst(const t_pair& pair1, const t_pair& pair2);	
	PmergeMe();
	PmergeMe(PmergeMe const & rhs);	
	PmergeMe & operator=(PmergeMe const & rhs);
public:
	PmergeMe(int argc, char **argv);
	~PmergeMe();
	void printInput();
	void printSortedSequence();
	void executeAlgo();

	class doublon : public std::exception {
		public:
			virtual const char* what() const throw();
	};

	class error : public std::exception {
		public:
			virtual const char* what() const throw();
	};
};

template <typename T, template<typename, typename> class Container>
void PmergeMe<T, Container>::_createPairAndSort(){
	typename Container<T, std::allocator<T> >::iterator it = _input.begin();
	_oddEl = (_input.size() % 2) != 0;
	for (unsigned int i = 0; i < (_input.size() / 2); ++i) { 
		_step1.push_back(Pair(*it++, *it++));
	}
	std::sort(_step1.begin(), _step1.end(), _compareFirst);
}

template <typename T, template<typename, typename> class Container>
void PmergeMe<T, Container>::_createMainAndPendChain(){
	typename Container<t_pair, std::allocator<t_pair> >::iterator ite = _step1.end();
	for (typename Container<t_pair, std::allocator<t_pair> >::iterator it = _step1.begin(); it != ite; ++it){
		_mainChain.push_back(it->first);
		_pendNb.push_back(it->second);
	}
	if (_oddEl)
		_pendNb.push_back(_input.back());
}

template <typename T, template<typename, typename> class Container>
unsigned int PmergeMe<T, Container>::_fordJohnsonTrick(unsigned int elToInsert){
	int pos = -1;
	int flag = 0;
	unsigned int j = 0;
	while (j < _step1.size()){
		pos++;
		if (_step1[j].second == elToInsert){
			flag = 1;
			break;
		}
		j++;
	}
	if (flag != 0){
		for (unsigned int i =  0; i < _mainChain.size(); i++){
			if (_step1[pos].first == _mainChain[i]){
				return i;
			}
		}
	}
	return _mainChain.size();
}

template <typename T, template<typename, typename> class Container>
void PmergeMe<T, Container>::_fordJohnsonAlgo(void){
	typename Container<T, std::allocator<T> >::iterator ite2  = _pendNb.end();
	unsigned int i = 0;
	for (typename Container<T, std::allocator<T> >::iterator it = _pendNb.begin(); it != ite2; ++it ){
		unsigned int elToinsert = _insertionOrder[i++] - 1;
		unsigned int left = 0;
		unsigned int right = _fordJohnsonTrick(_pendNb[elToinsert]);
		unsigned int m = (left + right) / 2;
		while (left < right){
			if (_mainChain[m] < _pendNb[elToinsert])
				left = m + 1;
			else if (_mainChain[m] > _pendNb[elToinsert])
				right = m;
			else
				break;
			m = (left + right) / 2;
		}
		_mainChain.insert(_mainChain.begin() + m, _pendNb[elToinsert]);
	}
}

template <typename T, template<typename, typename> class Container>
void PmergeMe<T, Container>::executeAlgo(){
	_createPairAndSort();
	_createMainAndPendChain();
	_createInsertionOrder();
	_fordJohnsonAlgo();
}

template <typename T, template<typename, typename> class Container>
PmergeMe<T, Container>::PmergeMe(int argc, char **argv){
	_parseInput(argc, argv);
}

template <typename T, template<typename, typename> class Container>
void PmergeMe<T, Container>::printSortedSequence(){
	std::cout << "After:   ";
	typename Container<T, std::allocator<T> >::iterator ite = _mainChain.end();
	for (typename Container<T, std::allocator<T> >::iterator it = _mainChain.begin(); it != ite; it++){
		std::cout << *it << "  " ;
	}
	std::cout << std::endl;
}

template <typename T, template<typename, typename> class Container>
void PmergeMe<T, Container>::printInput(){
	std::cout << "Before:  ";
	typename Container<T, std::allocator<T> >::iterator ite = _input.end();
	for (typename Container<T, std::allocator<T> >::iterator it = _input.begin(); it != ite; it++){
		std::cout << *it << "  " ;
	}
	std::cout << std::endl;
}

template <typename T, template<typename, typename> class Container>
const char* PmergeMe<T, Container>::doublon::what() const throw() {
    return "Doublon";
}

template <typename T, template<typename, typename> class Container>
const char* PmergeMe<T, Container>::error::what() const throw() {
    return "Error";
}

template <typename T, template<typename, typename> class Container>
bool PmergeMe<T, Container>::_isUInteger(const std::string& s) {
    std::istringstream iss(s);
    double temp;
	bool result = (iss >> temp) && iss.eof();
    return result && (temp >= 0) && (temp <= MAX_UINT);
}

template <typename T, template<typename, typename> class Container>
void PmergeMe<T, Container>::_parseInput(int 	argc, char **argv){
	try
	{
		if (argc == 1)
			throw PmergeMe::error(); 
		for (int i = 1; i < argc; i++){
			if (_isUInteger(argv[i])){
				if (std::find(_input.begin(), _input.end(), std::atoi(argv[i])) == _input.end())
					_input.push_back(std::atoi(argv[i]));
				else
					throw PmergeMe::doublon();
			}	
			else
				throw PmergeMe::error();
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		exit (1);
	}
	
}

template <typename T, template<typename, typename> class Container>
bool PmergeMe<T, Container>::_compareFirst(const t_pair& pair1, const t_pair& pair2) {
    return pair1.first < pair2.first;
}

template <typename T, template<typename, typename> class Container>
void PmergeMe<T, Container>::_createInsertionOrder(){
	if (_pendNb.size() >= 1)
		_insertionOrder.push_back(1);
	if (_pendNb.size() == 2)
		_insertionOrder.push_back(2);
	else{
		unsigned int lastJSN = 3;
		unsigned int lastlastJSN =1;
		unsigned int newJSN;
		int flag = 0;
		for (unsigned int j = 1; j < _pendNb.size(); j++){
			for (unsigned int i = lastJSN; i > lastlastJSN; --i)
				_insertionOrder.push_back(i);
			if (flag)
				break;
			newJSN = lastJSN + 2 * lastlastJSN;
			if (newJSN > _pendNb.size() - 1){
				newJSN = _pendNb.size();
				flag++;
			}
			lastlastJSN = lastJSN;
			lastJSN = newJSN;
		}
	}
}

template <typename T, template<typename, typename> class Container>
PmergeMe<T, Container>::PmergeMe(PmergeMe const & rhs){
	if (this  != &rhs)
		*this = rhs;
}

template <typename T, template<typename, typename> class Container>
PmergeMe<T, Container> & PmergeMe<T, Container>::operator=(PmergeMe const & rhs){
	(void)rhs;
	return *this;
}

template <typename T, template<typename, typename> class Container>
PmergeMe<T, Container>::PmergeMe(){
}

template <typename T, template<typename, typename> class Container>
PmergeMe<T, Container>::~PmergeMe(){
}

template <typename T, template<typename, typename> class Container>
void PmergeMe<T, Container>::_printVector(){
	typename Container<T, std::allocator<T> >::iterator ite = _input.end();
	for (typename Container<T, std::allocator<T> >::iterator it = _input.begin(); it != ite; ++it){
		std::cout << *it << " ";
	}
}

template <typename T, template<typename, typename> class Container>
void	PmergeMe<T, Container>::_printStep1(){
	typename Container<t_pair, std::allocator<t_pair> >::iterator ite = _step1.end();
	int i = 0;
	for (typename Container<t_pair, std::allocator<t_pair> >::iterator it = _step1.begin(); it != ite; it++){
		std::cout << "index: " << i++ << "|";
		it->print();
	}

}

template <typename T, template<typename, typename> class Container>
void	PmergeMe<T, Container>::_printStep2(){
	typename Container<T, std::allocator<T> >::iterator ite = _mainChain.end();
	std::cout <<"Main chain: ";
	for (typename Container<T, std::allocator<T> >::iterator it = _mainChain.begin(); it != ite; it++){
		std::cout << *it << "  " ;
	}
	std::cout << std::endl;

	typename Container<T, std::allocator<T> >::iterator ite2 = _pendNb.end();
	std::cout <<"Pend------: ";
	for (typename Container<T, std::allocator<T> >::iterator it = _pendNb.begin(); it != ite2; it++){
		std::cout << *it << "  " ;
	}
	std::cout << std::endl;

}

template <typename T, template<typename, typename> class Container>
void PmergeMe<T, Container>::_printIterationOrder(){
	typename Container<T, std::allocator<T> >::iterator ite = _insertionOrder.end();
	std::cout << "Iteration order sequence: ";
	for ( typename Container<T, std::allocator<T> >::iterator it = _insertionOrder.begin(); it != ite; ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

#endif