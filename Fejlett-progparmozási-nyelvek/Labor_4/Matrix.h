//
// Created by Boti on 3/12/2018.
//

#ifndef LABOR_4_MATRIX_H
#define LABOR_4_MATRIX_H

#include <iostream>
using namespace std;

class Matrix {
public:
    Matrix( int mRows = 10, int mCols = 10);
    Matrix( const Matrix& what );
    ~Matrix();

    // fills the matrix with identical elements
    void fillMatrix( double value );
    // fills the matrix with random numbers in the range [a, b)
    void randomMatrix( int a, int b );
    // prints the matrix
    void printMatrix( ostream& os = cout ) const;
    // checks whether this matrix is a square one
    bool isSquare() const;

private:
    double **mElements;
    int mRows;  // number of rows
    int mCols;  // number of columns
};


#endif //LABOR_4_MATRIX_H
