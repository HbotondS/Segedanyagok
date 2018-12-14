//
// Created by Boti on 3/25/2018.
//

#ifndef LABOR_6_MATRIX_H
#define LABOR_6_MATRIX_H

#include <iostream>
#include <stdexcept>

using namespace std;

class Matrix {
public:
    // Default constructor
    Matrix( int mRows = 10, int mCols =10);
    // Copy constructor
    Matrix( const Matrix& what );
    // Move constructor
    Matrix( Matrix&& what ) noexcept;
    // Destructor
    ~Matrix();
    // fills the matrix with identical elements: the value
    void fillMatrix( double value );
    // fills the matrix with random real numbers in the range [a, b)
    void randomMatrix( int a, int b );
    // prints the matrix
    void printMatrix( ostream& os = cout ) const;
    // checks whether this matrix is a square one
    bool isSquare() const;
    int getRows() const { return this->mRows; }
    int getCols() const { return this->mCols; }
    // csak egyenlo meretu matrixok eseteben engedelyezzuk az osszeadast
    friend Matrix operator+( const Matrix& x, const Matrix& y )throw ( out_of_range );
    friend Matrix operator*( const Matrix& x, const Matrix& y )throw ( out_of_range );
    friend istream & operator>>( istream& is, Matrix& mat );
    friend ostream & operator<<( ostream& os, const Matrix& mat );
    double* operator[] ( int index );
    double* operator[] ( int index ) const;

    // csak egyenlo meretu matrixok eseteben engedelyezzuk az ertekadast
    Matrix & operator=( const Matrix& mat ) throw ( out_of_range );
    // Move assignment
    Matrix & operator=( Matrix&& mat ) noexcept;
private:
    double ** mElements;
    int mRows; //number of rows
    int mCols; //number of columns
};

#endif //LABOR_6_MATRIX_H
