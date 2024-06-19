#include "Fixed.hpp"

int main( void ) {
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));
    Fixed d(Fixed(10) / Fixed(1.5f));

    std::cout << "a= "   << a << std::endl;
    std::cout << "a= "   << ++a << std::endl;
    std::cout << "a= "   << a << std::endl;
    std::cout << "a= "   << a++ << std::endl;
    std::cout << "a= "   << a << std::endl;

    std::cout << "d= "  << d << std::endl;
    std::cout << "d= "  << ++d << std::endl;
    std::cout << "d= "  << d << std::endl;
    std::cout << "d= "  << d++ << std::endl;
    std::cout << "d= "  << d << std::endl;
    std::cout << "b= " << b << std::endl;
    std::cout << "min between d and b " << Fixed::min( d, b ) << std::endl;
    std::cout << "max between a and b " <<  Fixed::max( a, b ) << std::endl;
    return 0;
}