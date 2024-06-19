#include <iostream>
#include "Array.hpp"
# include <cstdlib>
# include <ctime>

int main(void)
{
    Array <int> a(10);
    Array <std::string> b(10);
    Array <int> c(10);
    Array <Array <int> > d(2);
    Array <float> e(10);
    Array <int> h(a);
    Array <int> empt;
    Array <int> empt2(empt);

    std::cout << "--test 1--" << std::endl;
    try
    {
        a[0] = 1;
        a[6] = 8;
        std::cout << a[6] << std::endl;
        std::cout << a[50] << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "---test2---" << std::endl;
    try
    {
        b[6] = "bonjour";
        std::cout << b[6] << std::endl;
        std::cout << b[50] << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "--test 3--" << std::endl;
    try
    {
        e[0] = 42.0f;
        std::cout << e[0]  << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "--test 4--" << std::endl;
    try
    {
        d[0] = a;
        d[1] = c;
        std::cout << d[0][0]  << std::endl;
        std::cout << d[0][6]  << std::endl;
        std::cout << d[0][40] << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    
    std::cout << "--test 5--" << std::endl;
    try
    {
        std::cout << &empt  << std::endl;
        std::cout << empt.size()  << std::endl;        
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return (0);
}
