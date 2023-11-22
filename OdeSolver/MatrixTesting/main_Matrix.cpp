#include "../Matrix.hpp"
#include <iostream>

int main (int argc, char* argv[]){
    Matrix A(3,4);
    A(2,2) =1.0;
    for (int i=1; i<A.GetNumberOfRows()+1; i++){
        for (int j=1; j< A.GetNumberOfColumns() +1; j++){

            std::cout<<A(i,j)<<std::endl;
        }

    }

}