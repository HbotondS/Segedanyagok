//
// Created by Boti on 3/12/2018.
//

#include <time.h>
#include "Matrix.h"

Matrix::Matrix(int mRows, int mCols) {
    this->mElements = (double **)malloc(mRows * sizeof(double *));
    for (int i = 0; i < mRows; ++i) {
        mElements[i] = (double *)malloc(mCols * sizeof(double *));
    }
    this->mRows = mRows;
    this->mCols = mCols;
}

Matrix::Matrix(const Matrix &what) {
    this->mElements = what.mElements;
    this->mRows = what.mRows;
    this->mCols = what.mCols;
}

Matrix::~Matrix() {
    for (int i = 0; i < mRows; ++i) {
        free(mElements[i]);
    }
    free(mElements);
}

void Matrix::fillMatrix(double value) {
    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < mCols; ++j) {
            mElements[i][j] = value;
        }
    }
}

void Matrix::randomMatrix(int a, int b) {
    srand(time(NULL));
    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < mCols; ++j) {
            mElements[i][j] = rand() % (b-1) + a;
        }
    }
}

void Matrix::printMatrix(ostream &os) const {
    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < mCols; ++j) {
            os << mElements[i][j] << " ";
        }
        os << endl;
    }
}

bool Matrix::isSquare() const {
    return mRows == mCols;
}
