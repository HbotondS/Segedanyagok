//
// Created by Boti on 4/15/2018.
//

#ifndef LABOR_7_POLYNOMIAL_H
#define LABOR_7_POLYNOMIAL_H

#include <iostream>
using namespace std;

class Polynomial {
// Polinom együtthatói
    double *coefficients;
// Polinom együtthatóinak a száma
    int capacity;
public:
    Polynomial(int degree, const double coefficients[]);
    Polynomial(const Polynomial &that);
    Polynomial(Polynomial &&that);
    ~Polynomial();
// Polinom fokszáma
    int degree() const;
// Polinom értéke
    double evaluate(double x) const;
// Polinom deriváltja
    Polynomial derivative() const;
    double operator[](int index) const throw (out_of_range);
    friend Polynomial operator -(const Polynomial &a);
    friend Polynomial operator +(const Polynomial &a, const Polynomial &b);
    friend Polynomial operator -(const Polynomial &a, const Polynomial &b);
    friend Polynomial operator *(const Polynomial &a, const Polynomial &b);
    friend ostream & operator <<(ostream& out, const Polynomial& what);
};

#endif //LABOR_7_POLYNOMIAL_H
