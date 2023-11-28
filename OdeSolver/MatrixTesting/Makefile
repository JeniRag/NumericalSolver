

DIR = ..



Matrix.o: $(DIR)/Matrix.cpp $(DIR)/Matrix.hpp
		g++ -c -O  $(DIR)/Matrix.cpp

Vector.o: $(DIR)/Vector.cpp $(DIR)/Vector.hpp
	g++ -c -O $(DIR)/Vector.cpp

tests.cpp: MatrixTestSuite.hpp $(DIR)/Matrix.hpp $(DIR)/Vector.hpp
	cxxtestgen --error-printer -o  tests.cpp MatrixTestSuite.hpp 
tests.o: tests.cpp
	g++ -c -O tests.cpp

# Link Matrix.o and tests.o into the executable tests
tests: Vector.o Matrix.o tests.o
	g++ -O -o tests Vector.o Matrix.o tests.o

clean: rm -f Matrix.o main_Matrix.o main_Matrix tests.cpp tests




