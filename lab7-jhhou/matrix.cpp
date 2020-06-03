#include "matrix.h"

/*! \fn Matrix & operator*=(const Matrix &m) 
        \brief Compound multiplication assignment operator 

        Throw an invalid_argument exception when the dimensions of the matrices are not compatible
        Definition in cpp, implemented in terms of *

        \param m Matrix being multiplied to the LHS
        \return A reference to the matrix after multiplication
    */
    Matrix & Matrix::operator*=(const Matrix &m) {
        *this = *this * m;

        return *this;
    }