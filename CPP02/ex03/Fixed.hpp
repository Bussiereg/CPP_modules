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
    ~Fixed();

    Fixed& operator=(Fixed const & rhs);
    const Fixed operator+(Fixed const & rhs) const;
    const Fixed operator-(Fixed const & rhs) const;
    const Fixed operator*(Fixed const & rhs) const;
    const Fixed operator/(Fixed const & rhs) const;

    bool operator>(Fixed const & rhs) const;
    bool operator<(Fixed const & rhs) const;
    bool operator>=(Fixed const & rhs) const;
    bool operator<=(Fixed const & rhs) const;
    bool operator==(Fixed const & rhs) const;
    bool operator!=(Fixed const & rhs) const;

    Fixed & operator++();
    Fixed operator++(int);
    Fixed & operator--();
    Fixed operator--(int);


    static Fixed& min(Fixed & nb1, Fixed & nb2);
    static Fixed& max(Fixed & nb1, Fixed & nb2);
    static const Fixed& min(Fixed const & nb1, Fixed const & nb2);
    static const Fixed& max(Fixed const & nb1, Fixed const & nb2);

    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;
};

std::ostream & operator<<(std::ostream & o, Fixed const & rhs);

#endif