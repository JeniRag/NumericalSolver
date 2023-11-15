#include <cmath>
#include <iostream>
#include <cassert>
#include "Matrix.hpp"


// Overridden copy constructor
// Allocates memory for new vector, and copies
// entries of other vector into it
Matrix::Matrix(const Matrix& otherMatrix)
{
   mNumRows = otherMatrix.mNumRows;
   mNumCols = otherMatrix.mNumCols;
   mData = new double* [mNumRows];
   for (int i=0; i<mNumRows; i++)
   {
        mData[i] = new double [mNumCols];
        for (int j=0; j<mNumCols; j++)
        {

            mData[i][j]= otherMatrix.mData[i][j];
        }
      
   }
}

// Constructor for vector of a given size
// Allocates memory, and initialises entries
// to zero
Matrix::Matrix(int NumRows, int NumCols)
{
   assert(NumRows > 0);
   assert(NumCols >0);

   mNumRows = NumRows;
   mNumCols = NumCols;
   mData = new double* [mNumRows];
   for (int i=0; i<mNumRows; i++)
   {
    mData[i] = new double [mNumCols];
    for (int j = 0; j<mNumCols; j++)
    {
    mData[i][j] = 0.0;
    }
     
   }
}

// Overridden destructor to correctly free memory
Matrix::~Matrix()
{
    for (int i =0; i<mNumRows; i++){
        delete[] mData[i];
    }

   delete[] mData;
}

// Method to get the size of a vector
int Matrix::GetNumberOfRows() const
{
   return mNumRows;
}

int Matrix::GetNumberOfColumns() const{
    return mNumCols;
}

// 1-based indexing
double& Matrix::operator()(int i, int j)
{
   assert(i > 0);
   assert(i < mNumRows +1);

   assert(j>0);
   assert(j<mNumCols+1);
   return mData[i-1][j-1];
}

//Assignment operator
Matrix& Matrix::operator=(const Matrix& otherMatrix)
{
   assert(mNumRows == otherMatrix.mNumRows);
   assert(mNumCols == otherMatrix.mNumCols);
   for (int i=0; i<mNumRows; i++)
   {
   
    for (int j = 0; j<mNumCols; j++)
    {
    mData[i][j] = otherMatrix.mData[i][j];
    }     
   }

   return *this;
}

//unary + operator
Matrix Matrix::operator+() const
{
 
   Matrix A(mNumRows, mNumCols);
    //mData = new double* [mNumRows];

   for (int i=0; i<mNumRows; i++)
   {
    //mData[i] = new double [mNumCols];
    for (int j = 0; j<mNumCols; j++)
    {
    A(i+1, j+1) = mData[i][j];
    }
     
   }
  
   return A;
}
   // Overloading the unary - operator
Matrix Matrix::operator-() const
{
   Matrix A(mNumRows, mNumCols);
    //mData = new double* [mNumRows];

   for (int i=0; i<mNumRows; i++)
   {
    //mData[i] = new double [mNumCols];
    for (int j = 0; j<mNumCols; j++)
    {
    A(i+1, j+1) = -mData[i][j];
    }
     
   }
  
   return A;
}

// Overloading the binary + operator
Matrix Matrix::operator+(const Matrix& B) const
{
   assert(mNumRows == B.mNumRows);
   assert(mNumCols == B.mNumCols);
    Matrix C(mNumRows, mNumCols);

   for (int i=0; i<mNumRows; i++)
   {
        for (int j=0; j<mNumCols; j++)

        {

            C(i+1, j+1) = mData[i][j] + B.mData[i][j];
        }
      
   }
   return C;
}

// Overloading the binary - operator
Matrix Matrix::operator-(const Matrix& B) const
{
   assert(mNumRows == B.mNumRows);
   assert(mNumCols == B.mNumCols);
    Matrix C(mNumRows, mNumCols);

   for (int i=0; i<mNumRows; i++)
   {
        for (int j=0; j<mNumCols; j++)

        {

            C(i+1, j+1) = mData[i][j] - B.mData[i][j];
        }
      
   }
   return C;
}

// Overloading scalar multiplication
Matrix Matrix::operator*(double a) const
{
   Matrix C(mNumRows, mNumCols);
    for (int i=0; i<mNumRows; i++)
   {
        for (int j=0; j<mNumCols; j++)

        {

            C(i+1, j+1) = mData[i][j]*a;
        }
      
   }
   return C;
}

// double Matrix::CallculateDeterminant(){
//         return 0;

// }

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