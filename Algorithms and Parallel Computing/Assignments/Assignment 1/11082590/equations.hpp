#ifndef EQUATIONS_HPP
#define EQUATIONS_HPP

#include <string>

#include "utils.hpp"


class EquationFunction
{
public:
    EquationFunction( const std::string f_expr ): f_string( f_expr ) {}
    EquationFunction() = default;
    Rnvector eval( const double &t, Rnvector y ) const {
        return 5*y - 3 + 0*t;
    }
    std::string f_string = "y'(t) = 5*y(t) - 3";
};


#endif // EQUATIONS_HPP
