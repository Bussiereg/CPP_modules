#include "Point.hpp"

Point::Point() : _x(0),_y(0){
}

Point::~Point(){
}

Point::Point(const float x, const float y) : _x(x), _y(y) {
}

Point::Point(const Point & rhs){
    *this = rhs;
}

const Fixed Point::getX(void) const{
    return (this->_x);
}

const Fixed Point::getY(void) const{
    return (this->_y);
}

Point & Point::operator=(const Point & rhs){
    (Fixed)this->_x = rhs.getX();
    (Fixed)this->_y = rhs.getY();
    return *this;
}