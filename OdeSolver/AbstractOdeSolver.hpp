#ifndef ABSTRACTODESOLVERDEF
#define ABSTRACTODESOLVERDEF

class AbstractOdeSolver
{
    protected:
        double stepSize;
        double initialTime;
        double finalTime;
        double initialValue;

    public:
        void SetStepSize(double h);
        void SetTimeInterval(double t0, double t1);
        void SetInitialValue(double y0);
        virtual double RightHandSide(double y, double t) = 0 ; // pure virtual functions
        virtual double SolveEquation() = 0 ; // pure virtual functions
        // virtual functions are base class functions than can be redefined in a base class
        void SetRightHandSide();

};

#endif