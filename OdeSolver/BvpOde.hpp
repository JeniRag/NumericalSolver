#ifndef BVPODEHEADERDEF
#define BVPODEHEADERDEF

#include <string>
#include "Matrix.hpp"
#include "Vector.hpp"
#include "LinearSystem.hpp"
#include "FiniteDifferenceGrid.hpp"
#include "SecondOrderOde.hpp"
#include "BoundaryConditions.hpp"

class BvpOde
{
    private:
    // only allow instance to be created from a PDE, boundaryy conditions, and number of node in the mesh
    // copy constructor is private
    BvpOde(const BvpOde& otherBvpOde){}

    // Number of nodes in grid
    int mNumNodes;
    //ponter to a grid
    FiniteDifferenceGrid* mpGrid;

    //Pointer to instance of an ODE
    SecondOrderOde* mpOde;

    //Pointer to an instance of boundar conditions
    BoundaryConditions* mpBconds;

    // Vector for solution to unknowns
    Vector* mpSolVec;

    // Right-hand side vector
    Vector* mpRhsVec;

    //Matrix for linear system
    Matrix* mpLhsMat;

    //Linear system that arises
    LinearSystem* mpLinearSystem;

    //allow user to specifiy output file or use default name
    std::string mFilename;

    //Methods for setting up linear system and solving it
    void PopulateMatrix();
    void PopulateVector();
    void ApplyBoundaryConditions();

    public:
    //Sole constructor
    BvpOde(SecondOrderOde* pOde, BoundaryConditions* pBcs, int numNodes);

    //as memory is dynamically allocated the destructor is overridden
    ~BvpOde();

    void SetFilename(const std::string& name){
        mFilename = name;

    }
    void Solve();
    void WriteSolutionFile();

};

#endif