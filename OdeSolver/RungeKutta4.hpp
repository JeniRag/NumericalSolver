#ifndef RUNGEKUTTA4RDEF
#define RUNGEKUTTA4RDEF

#include "AbstractOdeSolver.hpp"

class  RungeKutta4: public AbstractOdeSolver{
    public:
        double RightHandSide( double t, double y);
        double SolveEquation();

};

#endif