make all: main 

AbstractOdeSolver.o: AbstractOdeSolver.cpp AbstractOdeSolver.hpp
	g++ -c -O AbstractOdeSolver.cpp

ForwardEulerSolver.o: ForwardEulerSolver.cpp ForwardEulerSolver.hpp	
	g++ -c -O ForwardEulerSolver.cpp

RungeKutta4.o: RungeKutta4.cpp RungeKutta4.hpp
	g++ -c -O RungeKutta4.cpp

main.o: main.cpp AbstractOdeSolver.hpp ForwardEulerSolver.hpp RungeKutta4.hpp
	g++ -c -O main.cpp

main: main.o AbstractOdeSolver.o ForwardEulerSolver.o RungeKutta4.o
	g++ -O -o main main.o AbstractOdeSolver.o ForwardEulerSolver.o RungeKutta4.o
