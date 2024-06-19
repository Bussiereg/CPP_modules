#include "Fixed.hpp"

// Public member functions

void Fixed::setRawBits(int const raw){
    this->_fixedPointValue = raw;
}

int Fixed::getRawBits(void) const{
    return this->_fixedPointValue;
}

float   Fixed::toFloat( void ) const{
    return ((float)this->getRawBits()) / (1 << _nbFractionalBits);
}

int Fixed::toInt(void) const{
    return _fixedPointValue >> _nbFractionalBits;
}

// Maximum and minimum function

Fixed& Fixed::min( Fixed &a, Fixed &b ) {
    if ( a.getRawBits() < b.getRawBits() )
        return a;
    return b;
}

const Fixed& Fixed::min( const Fixed &a, const Fixed &b ) {
    if ( a.getRawBits() < b.getRawBits() )
        return a;
    return b;
}

Fixed& Fixed::max( Fixed &a, Fixed &b ) {
    if ( a.getRawBits() > b.getRawBits() )
        return a;
    return b;
}

const Fixed& Fixed::max( const Fixed &a, const Fixed &b ) {
    if ( a.getRawBits() > b.getRawBits() )
        return a;
    return b;
}

// Copy assigment operator overload

Fixed& Fixed::operator=(Fixed const & rhs){
    this->setRawBits(rhs.getRawBits());
    return *this;
}

// Comparison operators

bool Fixed::operator>(const Fixed& rhs) const {
    return _fixedPointValue > rhs._fixedPointValue;
}

bool Fixed::operator<(const Fixed& rhs) const {
    return _fixedPointValue < rhs._fixedPointValue;
}

bool Fixed::operator>=(const Fixed& rhs) const {
    return _fixedPointValue >= rhs._fixedPointValue;
}

bool Fixed::operator<=(const Fixed& rhs) const {
    return _fixedPointValue <= rhs._fixedPointValue;
}

bool Fixed::operator==(const Fixed& rhs) const {
    return _fixedPointValue == rhs._fixedPointValue;
}

bool Fixed::operator!=(const Fixed& rhs) const {
    return _fixedPointValue != rhs._fixedPointValue;
}


// Increment and Decrement operators

Fixed& Fixed::operator++() {
    ++this->_fixedPointValue;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    temp._fixedPointValue = this->_fixedPointValue++;
    return temp;
}

Fixed& Fixed::operator--() {
    --this->_fixedPointValue;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    temp._fixedPointValue = this->_fixedPointValue--;
    return temp;
}

// Arithmetic operators

const Fixed Fixed::operator/(const Fixed& rhs) const {
    Fixed result(toFloat() / rhs.toFloat());
    return result;
}

const Fixed Fixed::operator+(const Fixed& rhs) const {
    Fixed result(toFloat() + rhs.toFloat());
    return result;
}

const Fixed Fixed::operator-(const Fixed& rhs) const {
    Fixed result(toFloat() - rhs.toFloat());
    return result;
}

const Fixed Fixed::operator*(const Fixed& rhs) const {
    Fixed result(toFloat() * rhs.toFloat());
    return result;
}

// Constructor

Fixed::Fixed(){
    setRawBits(0);
}

Fixed::Fixed(Fixed const& rhs){
    *this = rhs;
}

Fixed::Fixed(int const nb){
    setRawBits(nb * std::pow(2, _nbFractionalBits));
}

Fixed::Fixed(float const nb){
    setRawBits(roundf( nb * std::pow(2, _nbFractionalBits)));
}

// Destructor

Fixed::~Fixed(){
}

// Other

std::ostream & operator<<(std::ostream & o, Fixed const & rhs){
    o << rhs.toFloat();
    return o;
}