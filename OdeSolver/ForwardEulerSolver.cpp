#include "ForwardEulerSolver.hpp"

double ForwardEulerSolver::RightHandSide(double y, double t){
    
}

//Solves y_i = y_i-1 + h * f(t_i-1, y_i-1)
double ForwardEulerSolver::SolveEquation(){

    //t_i = T_0 + i * h
    // t_N = T_1 -> T_1 = T_0 + N * h <-> h = (T_1 -T_0)/h

    int N = (int) ((finalTime - initialTime) / stepSize );
    double y_prev = initialValue;
    double t_prev = initialTime;
    
    double (*p_function) (double y, double t);
    p_function = &RightHandSide;
    
    double y_i;
    double t_i;

    for (int i = 0; i < N; i++){
        y_i = y_prev + stepSize * p_function(y_prev, t_prev);
        t_i = initialTime + i* stepSize;
        y_prev = y_i;
        


    }
   
   
    


}