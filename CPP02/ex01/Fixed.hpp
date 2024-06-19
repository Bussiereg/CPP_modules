#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <ostream>
# include <cmath>

class Fixed
{
private:
    int _fixedPointValue;
    static int const _nbFractionalBits = 8;

public:
    Fixed();
    Fixed(int const nb);
    Fixed(float const nb);
    Fixed(Fixed const& rhs);
    Fixed& operator=(Fixed const & rhs);
    ~Fixed();

    int getRawBits(void) const;
    void setRawBits(int const raw);

    float toFloat(void) const;
    int toInt(void) const;


};

std::ostream & operator<<(std::ostream & o, Fixed const & rhs);

#endif