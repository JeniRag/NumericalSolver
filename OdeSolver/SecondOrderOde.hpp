#ifndef SECONDORDERODEHEADERDEF
#define SECONDORDERODEHEADERDEF

class SecondOrderOde{
    friend class BvpOde; //Boundary value class
    // friend class can access private and protected members of other classes in which it is declared as a friend.

private:
    //Coefficients on LHS of ODE
    double mCoeffOfUxx;
    double mCoeffOUx;
    double mCoeffOfU;
    //naming convention m -> to indicate member variables

    //function of RHS of ODE
    double (*mpRhsFunc) (double x);

    //Inteval for domain

    double mXmin;
    double mXmax;

public:
    SecondOrderOde(double coeffUxx, double coeffUx, double coeffU, double (*righthandSide) (double), double xMinimum, double xMaximum)
    {
        mCoeffOfUxx = coeffUxx;
        mCoeffOUx = coeffUx;
        mCoeffOfU = coeffU;
        mpRhsFunc = righthandSide;
        mXmin = xMinimum;
        mXmax = xMaximum;
        mpRhsFunc = righthandSide;
        mXmin = xMinimum;
        mXmax = xMaximum;
    }

};
#endif