#ifndef FORWARDEULERSOLVERDEF
#define FORWARDEULERSOLVERDEF

#include "AbstractOdeSolver.hpp"

class ForwardEulerSolver: public AbstractOdeSolver{
    public:
        double RightHandSide( double y, double t);
       //double (*RightHandSide)(double, double);
        double SolveEquation();
        //void SetRightHandSide(double (*pFunc)(double, double));

};

#endif