#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
private:
	const Fixed _x;
	const Fixed _y;

public:
	Point();
	Point(const float x, const float y);
	Point(const Point & rhs);
	Point & operator=(const Point & rhs);
	~Point();

	const Fixed getX(void) const;
	const Fixed getY(void) const;

};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif