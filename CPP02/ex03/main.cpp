#include "Point.hpp"

/* https://www.geogebra.org/graphing */
/* https://forums.futura-sciences.com/mathematiques-superieur/521026-caracteriser-point-a-linterieur-dun-triangle-quelconque.html */

int main( void ) {
    bool result = bsp(Point(2, 2), Point(5, 4), Point(6, 2), Point(4, 2.1));
    if (result == true)
        std::cout << "point inside" << std::endl;
    else
        std::cout << "point outside" << std::endl;
    return 0;
}