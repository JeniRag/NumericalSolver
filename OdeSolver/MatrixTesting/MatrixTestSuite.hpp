#include <cassert>
#include <cmath>
#include <cxxtest/TestSuite.h>
#include "../Matrix.hpp"

ostream &operator<<(ostream &os, const Matrix &M1)
{
    os << endl;
    os << "[";
    for (int i = 1; i < M1.GetNumberOfRows() + 1; i++)
    {
        for (int j = 1; j < M1.GetNumberOfColumns() + 1; j++)
        {
            os << M1.Read(i, j) << ", ";
        }
        os << endl;
    }
    os << "]" << endl;

    return os;
}

class MatrixTestSuite : public CxxTest::TestSuite
{
public:
    void TestDefaultConstructor(void)
    {
        Matrix A(4, 5);

        for (int i = 0; i < A.GetNumberOfRows(); i++)
        {
            for (int j = 0; j < A.GetNumberOfColumns(); j++)
            {
                TS_ASSERT_DELTA(A.mData[i][j], 0.0, 1.0e-16); // check in initialization all elements are 0.0
            }
        }
    }

    void TestCopyConstructor(void)
    {
        Matrix A(3, 3);
        A(1, 1) = 4;
        A(2, 2) = -4;
        A(3, 3) = -6;

        Matrix B(A);
        TS_ASSERT_EQUALS(A.mNumRows, B.mNumRows);
        TS_ASSERT_EQUALS(A.mNumCols, B.mNumCols);

        for (int i = 0; i < A.GetNumberOfRows(); i++)
        {
            for (int j = 0; j < A.GetNumberOfColumns(); j++)
            {
                TS_ASSERT_DELTA(A.mData[i][j] - B.mData[i][j], 0.0, 1.0e-16); // check in initialization all elements are 0.0
            }
        }
    }

    void TestGetDimensions(void)
    {
        Matrix A(4, 5);
        TS_ASSERT_EQUALS(A.GetNumberOfRows(), 4);
        TS_ASSERT_EQUALS(A.GetNumberOfColumns(), 5)
    }

    void TestRoundBracketOperator(void)
    {

        Matrix A(4, 5);

        A(1, 1) = -4;
        A(4, 5) = 10.0;
        TS_ASSERT_EQUALS(A.mData[0][0], -4);
        TS_ASSERT_EQUALS(A.mData[3][4], 10.0)
    }

    void TestBinarySum(void)
    {

        Matrix A(4, 5);
        Matrix B(4, 5);
        Matrix C(B.GetNumberOfRows(), B.GetNumberOfColumns());
        for (int i = 1; i < A.GetNumberOfRows() + 1; i++)
        {
            for (int j = 1; j < A.GetNumberOfColumns() + 1; j++)
            {
                A(i, j) = 1.0;
                B(i, j) = 2.0;
            }
        }
        C = A + B;

        for (int i = 1; i < C.GetNumberOfRows() + 1; i++)
        {
            for (int j = 1; j < C.GetNumberOfColumns() + 1; j++)
            {
                TS_ASSERT_DELTA(C(i, j), 3.0, 1e-6);
            }
        }
    }

    void TestUnarySum(void)
    {

        Matrix A(4, 5);

        for (int i = 1; i < A.GetNumberOfRows() + 1; i++)
        {
            for (int j = 1; j < A.GetNumberOfColumns() + 1; j++)
            {
                A(i, j) = i + j;
            }
        }

        Matrix B(A.GetNumberOfRows(), A.GetNumberOfColumns());
        B = +A;

        for (int i = 1; i < B.GetNumberOfRows() + 1; i++)
        {
            for (int j = 1; j < B.GetNumberOfColumns() + 1; j++)
            {
                TS_ASSERT_DELTA(B(i, j), i + j, 1e-6);
            }
        }
    }

    void TestBinaryMinus(void)
    {

        Matrix A(4, 5);
        Matrix B(4, 5);
        Matrix C(B.GetNumberOfRows(), B.GetNumberOfColumns());
        for (int i = 1; i < A.GetNumberOfRows() + 1; i++)
        {
            for (int j = 1; j < A.GetNumberOfColumns() + 1; j++)
            {
                A(i, j) = 1.0;
                B(i, j) = 2.0;
            }
        }
        C = A - B;

        for (int i = 1; i < C.GetNumberOfRows() + 1; i++)
        {
            for (int j = 1; j < C.GetNumberOfColumns() + 1; j++)
            {
                TS_ASSERT_DELTA(C(i, j), -1.0, 1e-6);
            }
        }
    }

    void TestUnaryMinus(void)
    {

        Matrix A(4, 5);

        for (int i = 1; i < A.GetNumberOfRows() + 1; i++)
        {
            for (int j = 1; j < A.GetNumberOfColumns() + 1; j++)
            {
                A(i, j) = i + j;
            }
        }

        // Matrix B(A.GetNumberOfRows(), A.GetNumberOfColumns());
        Matrix B = -A;

        for (int i = 1; i < B.GetNumberOfRows() + 1; i++)
        {
            for (int j = 1; j < B.GetNumberOfColumns() + 1; j++)
            {
                TS_ASSERT_DELTA(B(i, j), -(i + j), 1e-6);
            }
        }
    }

    void TestMultiplicationScalar(void)
    {

        Matrix A(4, 5);
        // Matrix B(A.GetNumberOfRows(), A.GetNumberOfColumns());
        for (int i = 1; i < A.GetNumberOfRows() + 1; i++)
        {
            for (int j = 1; j < A.GetNumberOfColumns() + 1; j++)
            {
                A(i, j) = 6.0;
            }
        }

        double a = 10.0;

        Matrix B = A * a;

        for (int i = 1; i < A.GetNumberOfRows() + 1; i++)
        {
            for (int j = 1; j < A.GetNumberOfColumns() + 1; j++)
            {
                TS_ASSERT_DELTA(B(i, j), 60.0, 1e-6);
            }
        }
    }

    void TestDeterminant2(void)
    {

        Matrix A(2, 2);

        A(1, 1) = 4;
        A(1, 2) = 0;
        A(2, 1) = 5;
        A(2, 2) = 6;

        double detA_expected = 24;
        TS_ASSERT_DELTA(A.CalculateDeterminant(), detA_expected, 1e-6);
    }

    void TestDeterminant3(void)
    {

        Matrix B(3, 3);
        B(1, 1) = 4;
        B(1, 2) = 5;
        B(1, 3) = 6;
        B(2, 1) = 8;
        B(2, 2) = 9;
        B(2, 3) = 11;
        B(3, 1) = 0;
        B(3, 2) = -8;
        B(3, 3) = -7;

        double detB_expected = -3.999999;
        TS_ASSERT_DELTA(B.CalculateDeterminant(), detB_expected, 1e-6);
    }

    void TestMatrixMatrixMultiplication(void)
    {
        Matrix A(3, 2);
        Matrix B(2, 4);

        A(1, 1) = -3;
        A(2, 1) = 5;
        A(3, 1) = 5;

        A(1, 2) = 4;
        A(2, 2) = 7;
        A(3, 2) = 6;

        B(1, 1) = 0;
        B(2, 1) = 8;

        B(1, 2) = 4;
        B(2, 2) = -10;

        B(1, 3) = -5;
        B(2, 3) = 34;

        B(1, 4) = 6;
        B(2, 4) = 5;

        Matrix C = A * B;
        Matrix C_expected(3, 4);

        C_expected(1, 1) = 32;
        C_expected(2, 1) = 56;
        C_expected(3, 1) = 48;

        C_expected(1, 2) = -52;
        C_expected(2, 2) = -50;
        C_expected(3, 2) = -40;

        C_expected(1, 3) = 151;
        C_expected(2, 3) = 213;
        C_expected(3, 3) = 179;

        C_expected(1, 4) = 2;
        C_expected(2, 4) = 65;
        C_expected(3, 4) = 60;

        TS_ASSERT_EQUALS(C.GetNumberOfRows(), C_expected.GetNumberOfRows());
        TS_ASSERT_EQUALS(C.GetNumberOfColumns(), C_expected.GetNumberOfColumns());

        for (int i = 1; i < C.GetNumberOfRows() + 1; i++)
        {
            for (int j = 1; j < C.GetNumberOfColumns() + 1; j++)
            {
                TS_ASSERT_DELTA(C(i, j), C_expected(i, j), 1e-6);
            }
        }

        delete A;
        delete B;
        delete C;
        delete C_expected;
    }


};