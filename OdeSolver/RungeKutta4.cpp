#include "RungeKutta4.hpp"


double RungeKutta4::RightHandSide(double t, double y){
    return 1+t;
}

//Solves y_i = y_i-1 + h * f(t_i-1, y_i-1)
double RungeKutta4::SolveEquation(){

    //t_i = T_0 + i * h
    // t_N = T_1 -> T_1 = T_0 + N * h <-> N = (T_1 -T_0)/h

    int N = (int) ((finalTime - initialTime) / stepSize );
    double y_i = initialValue;
    double t_i = initialTime;
    
    typedef double (RungeKutta4::*FunctionPointer)(double t, double y);
    FunctionPointer p_function = &RungeKutta4::RightHandSide;


    double k1, k2, k3, k4;

    for (int i = 0; i < N; i++){

        k1 = stepSize * (this->*p_function)(t_i, y_i);
        k2 = stepSize * (this->*p_function)(t_i + 1/2.0 * stepSize, y_i + 1/2.0 * k1);
        k3 = stepSize * (this->*p_function)(t_i + 1/2.0 * stepSize, y_i + 1/2.0 * k2);
        k4 = stepSize * (this->*p_function)(t_i + stepSize, y_i + k3);
    
        y_i  +=  1/6.0 * (k1 + 2*k2 + 2*k3 + k4); //y updated
        t_i = initialTime + i * stepSize; //t updated
        
        
    }
    

    return y_i;
   
   


}