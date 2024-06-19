#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <stdlib.h>
# include <string>
# include <cfloat>
# include <climits>
# include <limits>

class ScalarConverter
{
private:
    ScalarConverter();

public:
    ScalarConverter(ScalarConverter const & rhs);
    ScalarConverter & operator=(ScalarConverter const & rhs);
    ~ScalarConverter();

    static void convert(std::string & arg);
};




#endif