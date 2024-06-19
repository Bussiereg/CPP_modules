#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <deque>
#include <stack>

template< typename T, typename Container = std::deque< T > > 
class MutantStack : public std::stack< T, Container >
{
private:

public:

    MutantStack( void ) {};
    ~MutantStack( void ) {};

    MutantStack( const MutantStack& rhs ) { *this = rhs; }
    MutantStack&    operator=( const MutantStack& rhs ) {
        std::stack< T, Container >::operator=( rhs );
        return *this;
    }

    typedef typename Container::iterator    iterator;
    typedef typename Container::reverse_iterator    reverse_iterator;

    iterator    begin() { return this->c.begin(); }
    iterator    end() { return this->c.end(); }
    reverse_iterator    rbegin() { return this->c.rbegin(); }
    reverse_iterator    rend() { return this->c.rend(); }
};

#endif