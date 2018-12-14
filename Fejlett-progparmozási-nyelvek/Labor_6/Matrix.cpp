//
// Created by Boti on 3/25/2018.
//

#include <time.h>
#include "Matrix.h"

Matrix::Matrix(int mRows, int mCols):
        mRows(mRows),
        mCols(mCols)
{
    mElements = new double*[mRows];
    for (int i = 0; i < mRows; ++i) {
        mElements[i] = new double[mCols];
    }
}

Matrix::Matrix(const Matrix &what):
        mRows(what.mRows),
        mCols(what.mCols)
{
    mElements = new double*[mRows];
    for (int i = 0; i < mRows; ++i) {
        mElements[i] = new double[mCols];
    }

    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < mCols; ++j) {
            mElements[i][j] = what.mElements[i][j];
        }
    }
}

Matrix::Matrix(Matrix &&what) noexcept:
        mRows(what.mRows),
        mCols(what.mCols)
{
    mElements = new double*[mRows];
    for (int i = 0; i < mRows; ++i) {
        mElements[i] = new double[mCols];
    }

    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < mCols; ++j) {
            mElements[i][j] = what.mElements[i][j];
        }
    }

    for (int i = 0; i < what.mRows; ++i) {
        delete what.mElements[i];
    }
    delete what.mElements;
    what.mElements = nullptr;

    what.mCols = 0;
    what.mRows = 0;
}

Matrix::~Matrix() {
    if (mElements != nullptr) {
        for (int i = 0; i < mRows; ++i) {
            delete mElements[i];
        }
        delete mElements;
        mElements = nullptr;
    }

    mRows = 0;
    mCols = 0;
}

void Matrix::fillMatrix(double value) {
    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < mCols; ++j) {
            mElements[i][j] = value;
        }
    }
}

void Matrix::randomMatrix(int a, int b) {
    srand(time(nullptr));
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

Matrix operator+(const Matrix &x, const Matrix &y) throw ( out_of_range ) {
    Matrix temp = x;
    if (x.mCols != y.mCols && x.mRows != y.mRows) {
        throw out_of_range("The indexes are not the same");
    } else {
        for (int i = 0; i < x.mRows; ++i) {
            for (int j = 0; j < x.mCols; ++j) {
                temp.mElements[i][j] += y.mElements[i][j];
            }
        }
    }


    return temp;
}

Matrix operator*(const Matrix &x, const Matrix &y) throw ( out_of_range ) {
    Matrix temp(x.mRows, y.mCols);
    if (x.mCols != y.mRows) {
        throw out_of_range("The indexes are not the same");
    } else {
        int sum = 0;
        for (int i = 0; i < x.mRows; ++i) {
            for (int j = 0; j < y.mCols; ++j) {
                for (int k = 0; k < y.mRows; ++k) {
                    sum += x.mElements[i][k] * y.mElements[k][j];
                }

                temp.mElements[i][j] = sum;
                sum = 0;
            }
        }
    }

    return temp;
}

ostream &operator<<(ostream &os, const Matrix &mat) {
    mat.printMatrix(os);

    return os;
}

istream &operator>>(istream &is, Matrix &mat) {
    for (int i = 0; i < mat.mRows; ++i) {
        for (int j = 0; j < mat.mCols; ++j) {
            is >> mat.mElements[i][j];
        }
    }

    return is;
}

double *Matrix::operator[](int index) {
    return mElements[index];
}

double *Matrix::operator[](int index) const {
    return mElements[index];
}

Matrix &Matrix::operator=(const Matrix &mat) throw ( out_of_range ) {
    if (mCols != mat.mCols && mRows != mat.mRows) {
        throw out_of_range("The indexes are not the same");
    } else {
        if (&mat != this) {
            for (int i = 0; i < mRows; ++i) {
                for (int j = 0; j < mCols; ++j) {
                    mElements[i][j] = mat.mElements[i][j];
                }
            }

            return *this;
        }
    }
}

Matrix &Matrix::operator=(Matrix &&mat) noexcept {
    if (&mat != this) {
        for (int i = 0; i < mRows; ++i) {
            for (int j = 0; j < mCols; ++j) {
                mElements[i][j] = mat.mElements[i][j];
            }
        }
        for (int i = 0; i < mat.mRows; ++i) {
            delete mat.mElements[i];
        }
        delete mat.mElements;
        mat.mElements = nullptr;
        mat.mCols = 0;
        mat.mRows = 0;

        return *this;
    }
}
