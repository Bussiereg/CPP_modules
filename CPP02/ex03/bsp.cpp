#include "Point.hpp"	

bool bsp(Point const a, Point const b, Point const c, Point const point){
	Fixed(APB) =  ((a.getX() - point.getX()) * (b.getY() - point.getY())) - ((a.getY() - point.getY()) * (b.getX() - point.getX()));
	Fixed(BPC) = ((b.getX() - point.getX()) * (c.getY() - point.getY())) - ((b.getY() - point.getY()) * (c.getX() - point.getX()));
	Fixed(CPA) = ((c.getX() - point.getX()) * (a.getY() - point.getY())) - ((c.getY() - point.getY()) * (a.getX() - point.getX()));
	
	return ((APB > 0 && BPC > 0 && CPA > 0) || (APB < 0 && BPC < 0 && CPA < 0));
}