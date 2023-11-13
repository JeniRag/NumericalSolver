#include "ForwardEulerSolver.hpp"


double ForwardEulerSolver::RightHandSide(double t, double y){
    return 1+t;
    }

//Solves y_i = y_i-1 + h * f(t_i-1, y_i-1)
double ForwardEulerSolver::SolveEquation(){

    //t_i = T_0 + i * h
    // t_N = T_1 -> T_1 = T_0 + N * h <-> N = (T_1 -T_0)/h

    int N = (int) ((finalTime - initialTime) / stepSize ); //number of steps
    double y_i = initialValue;
    double t_i = initialTime;
    
    typedef double (ForwardEulerSolver::*FunctionPointer)(double t, double y); 
    FunctionPointer p_function = &ForwardEulerSolver::RightHandSide; // declare function pointer
     


    for (int i = 0; i < N; i++){
        y_i  += stepSize * (this->*p_function)(t_i, y_i); //update y
        t_i = initialTime + i* stepSize; //update y
     
        
    }

    return y_i;
   


}

// void ForwardEulerSolver::SetRightHandSide(double (*pFunc)(double, double)){

//     RightHandSide = pFunc;
// }