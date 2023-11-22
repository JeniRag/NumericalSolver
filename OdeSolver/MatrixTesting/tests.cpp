/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/TestMain.h>
#include <cxxtest/ErrorPrinter.h>

int main( int argc, char *argv[] ) {
 int status;
    CxxTest::ErrorPrinter tmp;
    CxxTest::RealWorldDescription::_worldName = "cxxtest";
    status = CxxTest::Main< CxxTest::ErrorPrinter >( tmp, argc, argv );
    return status;
}
bool suite_MatrixTestSuite_init = false;
#include "MatrixTestSuite.hpp"

static MatrixTestSuite suite_MatrixTestSuite;

static CxxTest::List Tests_MatrixTestSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_MatrixTestSuite( "MatrixTestSuite.hpp", 24, "MatrixTestSuite", suite_MatrixTestSuite, Tests_MatrixTestSuite );

static class TestDescription_suite_MatrixTestSuite_TestDefaultConstructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MatrixTestSuite_TestDefaultConstructor() : CxxTest::RealTestDescription( Tests_MatrixTestSuite, suiteDescription_MatrixTestSuite, 27, "TestDefaultConstructor" ) {}
 void runTest() { suite_MatrixTestSuite.TestDefaultConstructor(); }
} testDescription_suite_MatrixTestSuite_TestDefaultConstructor;

static class TestDescription_suite_MatrixTestSuite_TestCopyConstructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MatrixTestSuite_TestCopyConstructor() : CxxTest::RealTestDescription( Tests_MatrixTestSuite, suiteDescription_MatrixTestSuite, 39, "TestCopyConstructor" ) {}
 void runTest() { suite_MatrixTestSuite.TestCopyConstructor(); }
} testDescription_suite_MatrixTestSuite_TestCopyConstructor;

static class TestDescription_suite_MatrixTestSuite_TestGetDimensions : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MatrixTestSuite_TestGetDimensions() : CxxTest::RealTestDescription( Tests_MatrixTestSuite, suiteDescription_MatrixTestSuite, 58, "TestGetDimensions" ) {}
 void runTest() { suite_MatrixTestSuite.TestGetDimensions(); }
} testDescription_suite_MatrixTestSuite_TestGetDimensions;

static class TestDescription_suite_MatrixTestSuite_TestRoundBracketOperator : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MatrixTestSuite_TestRoundBracketOperator() : CxxTest::RealTestDescription( Tests_MatrixTestSuite, suiteDescription_MatrixTestSuite, 65, "TestRoundBracketOperator" ) {}
 void runTest() { suite_MatrixTestSuite.TestRoundBracketOperator(); }
} testDescription_suite_MatrixTestSuite_TestRoundBracketOperator;

static class TestDescription_suite_MatrixTestSuite_TestBinarySum : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MatrixTestSuite_TestBinarySum() : CxxTest::RealTestDescription( Tests_MatrixTestSuite, suiteDescription_MatrixTestSuite, 75, "TestBinarySum" ) {}
 void runTest() { suite_MatrixTestSuite.TestBinarySum(); }
} testDescription_suite_MatrixTestSuite_TestBinarySum;

static class TestDescription_suite_MatrixTestSuite_TestUnarySum : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MatrixTestSuite_TestUnarySum() : CxxTest::RealTestDescription( Tests_MatrixTestSuite, suiteDescription_MatrixTestSuite, 100, "TestUnarySum" ) {}
 void runTest() { suite_MatrixTestSuite.TestUnarySum(); }
} testDescription_suite_MatrixTestSuite_TestUnarySum;

static class TestDescription_suite_MatrixTestSuite_TestBinaryMinus : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MatrixTestSuite_TestBinaryMinus() : CxxTest::RealTestDescription( Tests_MatrixTestSuite, suiteDescription_MatrixTestSuite, 126, "TestBinaryMinus" ) {}
 void runTest() { suite_MatrixTestSuite.TestBinaryMinus(); }
} testDescription_suite_MatrixTestSuite_TestBinaryMinus;

static class TestDescription_suite_MatrixTestSuite_TestUnaryMinus : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MatrixTestSuite_TestUnaryMinus() : CxxTest::RealTestDescription( Tests_MatrixTestSuite, suiteDescription_MatrixTestSuite, 153, "TestUnaryMinus" ) {}
 void runTest() { suite_MatrixTestSuite.TestUnaryMinus(); }
} testDescription_suite_MatrixTestSuite_TestUnaryMinus;

static class TestDescription_suite_MatrixTestSuite_TestMultiplicationScalar : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MatrixTestSuite_TestMultiplicationScalar() : CxxTest::RealTestDescription( Tests_MatrixTestSuite, suiteDescription_MatrixTestSuite, 180, "TestMultiplicationScalar" ) {}
 void runTest() { suite_MatrixTestSuite.TestMultiplicationScalar(); }
} testDescription_suite_MatrixTestSuite_TestMultiplicationScalar;

static class TestDescription_suite_MatrixTestSuite_TestDeterminant2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MatrixTestSuite_TestDeterminant2() : CxxTest::RealTestDescription( Tests_MatrixTestSuite, suiteDescription_MatrixTestSuite, 207, "TestDeterminant2" ) {}
 void runTest() { suite_MatrixTestSuite.TestDeterminant2(); }
} testDescription_suite_MatrixTestSuite_TestDeterminant2;

static class TestDescription_suite_MatrixTestSuite_TestDeterminant3 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MatrixTestSuite_TestDeterminant3() : CxxTest::RealTestDescription( Tests_MatrixTestSuite, suiteDescription_MatrixTestSuite, 224, "TestDeterminant3" ) {}
 void runTest() { suite_MatrixTestSuite.TestDeterminant3(); }
} testDescription_suite_MatrixTestSuite_TestDeterminant3;

static class TestDescription_suite_MatrixTestSuite_TestMatrixMultiplication : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MatrixTestSuite_TestMatrixMultiplication() : CxxTest::RealTestDescription( Tests_MatrixTestSuite, suiteDescription_MatrixTestSuite, 243, "TestMatrixMultiplication" ) {}
 void runTest() { suite_MatrixTestSuite.TestMatrixMultiplication(); }
} testDescription_suite_MatrixTestSuite_TestMatrixMultiplication;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
