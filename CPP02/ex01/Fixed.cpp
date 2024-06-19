#include "Fixed.hpp"

// Public member functions

void Fixed::setRawBits(int const raw){
    this->_fixedPointValue = raw;
}

int Fixed::getRawBits(void) const {
    return this->_fixedPointValue;
}

float   Fixed::toFloat( void ) const {
    return static_cast<float>(this->getRawBits()) / (1 << _nbFractionalBits);
}

int Fixed::toInt(void) const{
    return _fixedPointValue >> _nbFractionalBits;
}

// Copy assigment operator overload

Fixed& Fixed::operator=(Fixed const & rhs){
    std::cout << "Copy assigment operator called" << std::endl; 
    this->setRawBits(rhs.getRawBits());
    return *this;
}

// Constructor

Fixed::Fixed()
{
    this->_fixedPointValue = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const& rhs){
    std::cout << "Copy constructor called" << std::endl;
    *this = rhs;
}

Fixed::Fixed(int const nb){
    std::cout << "Int constructor called" << std::endl;
    setRawBits(nb * std::pow(2, _nbFractionalBits));
}

Fixed::Fixed(float const nb){
    std::cout << "Float constructor called" << std::endl;
    setRawBits(roundf( nb * std::pow(2, _nbFractionalBits)));
}

// Destructor

Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;
}

// Other

std::ostream & operator<<(std::ostream & o, Fixed const & rhs){
    o << rhs.toFloat();
    return o;
}