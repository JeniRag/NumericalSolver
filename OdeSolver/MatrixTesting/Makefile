

DIR = ..
Matrix.o: $(DIR)/Matrix.cpp $(DIR)/Matrix.hpp
		g++ -c -O  $(DIR)/Matrix.cpp


main_Matrix.o: main_Matrix.cpp $(DIR)/Matrix.hpp
	g++ -c -O main_Matrix.cpp

main_Matrix: Matrix.o main_Matrix.o
	g++ -O -o main_Matrix Matrix.o main_Matrix.o

tests.cpp: MatrixTestSuite.hpp $(DIR)/Matrix.hpp
	cxxtestgen --error-printer -o  tests.cpp MatrixTestSuite.hpp 
tests.o: tests.cpp
	g++ -c -O tests.cpp

# Link Matrix.o and tests.o into the executable tests
tests: Matrix.o tests.o
	g++ -O -o tests Matrix.o tests.o

clean: rm -f Matrix.o main_Matrix.o main_Matrix tests.cpp tests




