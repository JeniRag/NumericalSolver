#include <cmath>
#include <iostream>
#include <cassert>
#include "Matrix.hpp"
#include "Vector.hpp"
using namespace std;

// Overridden copy constructor
// Allocates memory for new vector, and copies
// entries of other vector into it

// ostream& operator<<(ostream& os, const Matrix& M1)
// {
//    os<<"[";
//    for (int i=1; i<M1.GetNumberOfRows()+1; i++){
//       for (int j=1; j<M1.GetNumberOfColumns()+1; j++){
//          os<<M1(i,j) << " ";
//       }
//       os<<endl;
//    }
//    os<<"]"<<endl;

//    return os;
// }

Matrix::Matrix(const Matrix &otherMatrix)
{
   mNumRows = otherMatrix.mNumRows;
   mNumCols = otherMatrix.mNumCols;
   mData = new double *[mNumRows];
   for (int i = 0; i < mNumRows; i++)
   {
      mData[i] = new double[mNumCols];
      for (int j = 0; j < mNumCols; j++)
      {

         mData[i][j] = otherMatrix.mData[i][j];
      }
   }
}

// Constructor for vector of a given size
// Allocates memory, and initialises entries
// to zero
Matrix::Matrix(int NumRows, int NumCols)
{
   assert(NumRows > 0);
   assert(NumCols > 0);

   mNumRows = NumRows;
   mNumCols = NumCols;
   mData = new double *[mNumRows];
   for (int i = 0; i < mNumRows; i++)
   {
      mData[i] = new double[mNumCols];
      for (int j = 0; j < mNumCols; j++)
      {
         mData[i][j] = 0.0;
      }
   }
}

// Overridden destructor to correctly free memory
Matrix::~Matrix()
{
   for (int i = 0; i < mNumRows; i++)
   {
      delete[] mData[i];
   }

   delete[] mData;
}

// Method to get the size of a vector
int Matrix::GetNumberOfRows() const
{
   return mNumRows;
}

int Matrix::GetNumberOfColumns() const
{
   return mNumCols;
}

double Matrix::Read(int i, int j) const
{
   assert(i > 0);
   assert(i < mNumRows + 1);
   assert(j > 0);
   assert(j < mNumCols + 1);
   return mData[i - 1][j - 1];
}

// 1-based indexing
double &Matrix::operator()(int i, int j)
{
   assert(i > 0);
   assert(i < mNumRows + 1);

   assert(j > 0);
   assert(j < mNumCols + 1);
   return mData[i - 1][j - 1];
}

// Assignment operator
Matrix &Matrix::operator=(const Matrix &otherMatrix)
{
   assert(mNumRows == otherMatrix.mNumRows);
   assert(mNumCols == otherMatrix.mNumCols);
   for (int i = 0; i < mNumRows; i++)
   {

      for (int j = 0; j < mNumCols; j++)
      {
         mData[i][j] = otherMatrix.mData[i][j];
      }
   }

   return *this;
}

// unary + operator
Matrix Matrix::operator+() const
{

   Matrix A(mNumRows, mNumCols);
   // mData = new double* [mNumRows];

   for (int i = 0; i < mNumRows; i++)
   {
      // mData[i] = new double [mNumCols];
      for (int j = 0; j < mNumCols; j++)
      {
         A(i + 1, j + 1) = mData[i][j];
      }
   }

   return A;
}
// Overloading the unary - operator
Matrix Matrix::operator-() const
{
   Matrix A(mNumRows, mNumCols);
   // mData = new double* [mNumRows];

   for (int i = 0; i < mNumRows; i++)
   {
      // mData[i] = new double [mNumCols];
      for (int j = 0; j < mNumCols; j++)
      {
         A(i + 1, j + 1) = -mData[i][j];
      }
   }

   return A;
}

// Overloading the binary + operator
Matrix Matrix::operator+(const Matrix &B) const
{
   assert(mNumRows == B.mNumRows);
   assert(mNumCols == B.mNumCols);
   Matrix C(mNumRows, mNumCols);

   for (int i = 0; i < mNumRows; i++)
   {
      for (int j = 0; j < mNumCols; j++)

      {

         C(i + 1, j + 1) = mData[i][j] + B.mData[i][j];
      }
   }
   return C;
}

// Overloading the binary - operator
Matrix Matrix::operator-(const Matrix &B) const
{
   assert(mNumRows == B.mNumRows);
   assert(mNumCols == B.mNumCols);
   Matrix C(mNumRows, mNumCols);

   for (int i = 0; i < mNumRows; i++)
   {
      for (int j = 0; j < mNumCols; j++)

      {

         C(i + 1, j + 1) = mData[i][j] - B.mData[i][j];
      }
   }
   return C;
}

// Overloading scalar multiplication
Matrix Matrix::operator*(double a) const
{
   Matrix C(mNumRows, mNumCols);
   for (int i = 0; i < mNumRows; i++)
   {
      for (int j = 0; j < mNumCols; j++)

      {

         C(i + 1, j + 1) = mData[i][j] * a;
      }
   }
   return C;
}

// Multiplication of two Matrices
Matrix Matrix::operator*(const Matrix& B) const
{

   assert(mNumCols == B.mNumRows);

   Matrix C(mNumRows, B.mNumCols);

   for (int i = 0; i < mNumRows; i++)
   {

      for (int j = 0; j < B.mNumCols; j++)
      {

         double value = 0.0;

         for (int k = 0; k < mNumCols; k++)
         {
            value += mData[i][k] * B.mData[k][j];
         }

         C(i + 1, j + 1) = value;
      }
   }
   //cout << C << endl;
   return C;
}

// Multiplication of Matrix with Vector
Vector operator*(const Matrix& A, const Vector& b)
{
   int vector_size = b.GetSize();
   assert(A.GetNumberOfColumns() == vector_size);
   Vector c(A.GetNumberOfRows());

   for (int i = 0; i < A.GetNumberOfRows(); i++)
   {

      double value = 0.0;

      for (int k = 0; k < A.GetNumberOfColumns(); k++)
      {
         value += A.mData[i][k] * b.Read(k);
      }

      c(i + 1) = value;
   }

   return c;
}

// Vector multiplied by Matrix
Vector operator*(const Vector& b, const Matrix& A)
{
   assert(b.GetSize() == A.GetNumberOfRows());

   Vector c(A.GetNumberOfColumns());

   for (int i = 0; i < b.GetSize(); i++)
   {
      for (int k = 0; k < A.GetNumberOfColumns(); k++)
      {
         c(k + 1) += b.Read(i) * A.mData[i][k];
      }
   }
   return c;
}

double Matrix::CalculateDeterminant()
{

   assert(mNumCols == mNumRows); // check if it is square matrix

   // initialize a value
   double determinant = 0.0;

   if (mNumCols == 1)
   {
      // determinant = mData[0][0];
      determinant = mData[0][0];
   }

   else
   {

      int N = mNumCols;
      // cout << "N = " << N << endl;
      int i = 0;

      // for (int i = 0; i < 1; i++)
      // {

      for (int j = 0; j < N; j++)
      {
         // cout << i << " and " << j << " removed" << endl;
         Matrix subA(N - 1, N - 1); // square matrix of size N-1
         int r = 0;                 // initiate index to populate new matrix
         // populate matrix
         for (int ki = 0; ki < N; ki++)
         { // iteration over new matrix size
            // cout<<"r: "<<r<<endl;
            int c = 0;
            if (ki != i) // omit the i-th row
            {
               int test = 0;
               for (int kj = 0; kj < N; kj++)
               {

                  if (kj != j)
                  { // omit the j-th column

                     // cout << "(" << r << ", " << c << ") populated with "
                     //      << "( " << ki << ", " << kj << ")" << endl;
                     // cout<<"r: "<<r<<endl;
                     assert(r < N - 1);
                     assert(c < N - 1);
                     subA.mData[r][c] = mData[ki][kj];
                     c++; // populate next column
                  }
               }
               r++;
            }
         }
         // cout << "Determinant of: " <<subA  <<"is "<<subA.CalculateDeterminant()<< endl;
         determinant += pow(-1, j) * subA.CalculateDeterminant() * mData[i][j];
         // cout<< "adding: "<< pow(-1, j) <<"*" <<subA.CalculateDeterminant()<<"*" <<mData[i][j]<<endl;
      }
      //}
   }

   return determinant;
}

/*






// Method to calculate norm (with default value p=2)
// corresponding to the Euclidean norm
double Vector::CalculateNorm(int p) const
{
   double norm_val, sum = 0.0;
   for (int i=0; i<mSize; i++)
   {
      sum += pow(fabs(mData[i]), p);
   }
   norm_val = pow(sum, 1.0/((double)(p)));
   return norm_val;
}

// MATLAB style friend to get the size of a vector
int length(const Vector& v)
{
   return v.mSize;
}
//Code from Chapter10.tex line 62 save as Vector.cpp
*/