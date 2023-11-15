#ifndef MATRIXHEADERDEF
#define MATRIXHEADERDEF

class Matrix
{
private:
   double** mData; // data stored in matrix. adress of the poitner to the first entry of the first row
   int mNumRows; //number of rows
   int mNumCols; // number of columns
  
public:
    friend class MatrixTestSuite; // allows the testsuite to access private members.
   //Constructors
   Matrix(const Matrix& otherMatrix); //Copy Constructor
   Matrix(int NumRows, int NumCols);

   //Destructor
   ~Matrix();

   int GetNumberOfRows() const;
   int GetNumberOfColumns() const;

   //operators
   double& operator()(int i, int j); //indexing & since it returns the data
  // double& operator[](int i, int j); //indexing & since it returns the data
   Matrix& operator=(const Matrix& otherMatrix);
   Matrix operator+() const; //unary
   Matrix operator-() const;
   Matrix operator+(const Matrix& M1) const; //binary
   Matrix operator-(const Matrix& M1) const;
   Matrix operator*(double a) const;
   
   double CallculateDeterminant();

};

// Prototype signature of length() friend function
//int length(const Vector& v);

#endif

