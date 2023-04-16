make all: main 

AbstractOdeSolver.o: AbstractOdeSolver.cpp AbstractOdeSolver.hpp
	g++ -c -O AbstractOdeSolver.cpp

ForwardEulerSolver.o: ForwardEulerSolver.cpp ForwardEulerSolver.hpp	
	g++ -c -O ForwardEulerSolver.cpp

main.o: main.cpp AbstractOdeSolver.hpp ForwardEulerSolver.hpp
	g++ -c -O main.cpp

main: main.o AbstractOdeSolver.o ForwardEulerSolver.o
	g++ -O -o main main.o AbstractOdeSolver.o ForwardEulerSolver.o
