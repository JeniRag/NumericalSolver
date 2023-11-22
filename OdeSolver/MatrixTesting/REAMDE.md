To use the CXX Test Suites:
``` 
cxxtestgen --error-printer -o tests.cpp TestSuite.hpp 
g++ -o main tests.cpp
./main
```