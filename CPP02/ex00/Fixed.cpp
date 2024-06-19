#include <iostream>
#include "Fixed.hpp"

void Fixed::setRawBits(int const raw){
    this->_fixedPointValue = raw;
}


int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->_fixedPointValue;
}

Fixed::Fixed(Fixed const& rhs){
    std::cout << "Copy constructor called" << std::endl;
    *this = rhs;
}

Fixed& Fixed::operator=(Fixed const & rhs){
    std::cout << "Copy assigment operator called" << std::endl; 
    this->setRawBits(rhs.getRawBits());
    return *this;
}

Fixed::Fixed()
{
    this->setRawBits(0);
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}