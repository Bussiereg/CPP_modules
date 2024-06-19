#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <list>
#include <algorithm>
#include <vector>

template <typename T>
int easyfind(T &lhs, int rhs)
{
    typename T::const_iterator it = lhs.begin();
    typename T::const_iterator ite = lhs.end();

    if (std::find(it, ite, rhs)  != ite ){
        std::cout << rhs << " has been found." << std::endl;
        return 0;
    }
    std::cout << rhs << " has not been found." << std::endl;
    return 1;
}

#endif