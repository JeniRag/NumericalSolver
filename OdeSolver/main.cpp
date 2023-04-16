#include <iostream>
#include <cmath>
#include "AbstractOdeSolver.hpp"
#include "ForwardEulerSolver.hpp"


double exact_solution_FES(double y, double t);

int main (int argc, char* argv[]){
    //ForwardEuler
    

   
    double y = 2;
    double tstart = 0;
    double tend = 1;

    
    std::cout <<"The exact solution is: "<< exact_solution_FES(y, tend)<<std::endl; 


    double h[3]  {0.001, 0.01, 0.1};
    for (int i=0; i<3; i++){
        ForwardEulerSolver FES;
        FES.SetStepSize(h[i]);
        FES.SetInitialValue(y);
        FES.SetTimeInterval(tstart, tend);
        double y_res = FES.SolveEquation();

        std::cout<<"The result of Forward Euler is with h = "<<h[i] << " is: "<< y_res <<std::endl;

    }


}

double exact_solution_FES(double y, double t){
    return (pow(t,2) + 2*t + 4) / 2;
}