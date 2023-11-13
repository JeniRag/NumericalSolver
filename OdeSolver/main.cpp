#include <iostream>
#include <cmath>
#include "AbstractOdeSolver.hpp"
#include "ForwardEulerSolver.hpp"
#include "RungeKutta4.hpp"

double exact_solution_FES(double y, double t);
double myRightHandSide(double t, double y);

int main (int argc, char* argv[]){
    double y = 2;
    double tstart = 0;
    double tend = 1;

    
    std::cout <<"The exact solution is: "<< exact_solution_FES(y, tend)<<std::endl; 

    
    double h[4] =  {0.0001, 0.001, 0.01, 0.1};
    int N = sizeof(h) / sizeof(double);

   // double (*p_function)(double t, double y);
    // &p_function = &myFunction;

    std::cout<<"---------Forward Euler --------------"<< std::endl;
    for (int i=0; i<N; i++){
        ForwardEulerSolver FES;
        FES.SetStepSize(h[i]);
        FES.SetInitialValue(y);
        FES.SetTimeInterval(tstart, tend);
        //FES.SetRightHandSide(myRightHandSide);
        double y_res = FES.SolveEquation();

        std::cout<<"The result with h = "<<h[i] << " is: "<< y_res <<std::endl;

    }
    
    std::cout<<"---------Runge Kutta 4 --------------"<< std::endl;
    for (int i=0; i <N ; i++){
        RungeKutta4 RK;
        RK.SetStepSize(h[i]);
        RK.SetInitialValue(y);
        RK.SetTimeInterval(tstart, tend);
        double y_res = RK.SolveEquation();

        std::cout<<"The result with h = "<<h[i] << " is: "<< y_res <<std::endl;

    }
    


}

double myRightHandSide(double t, double y){
    return 1+t;
}

double exact_solution_FES(double y, double t){
    return (pow(t,2) + 2*t + 4) / 2;
}