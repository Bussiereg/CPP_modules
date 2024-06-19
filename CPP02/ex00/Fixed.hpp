#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
private:
    int _fixedPointValue;
    static int const _nbFractionalBits = 8;

public:
    Fixed();
    Fixed(Fixed const& rhs);
    Fixed& operator=(Fixed const & rhs);
    ~Fixed();

    int getRawBits(void) const;
    void setRawBits(int const raw);

};

#endif