//
// Created by Boti on 4/15/2018.
//

#include "Polynomial.h"

Polynomial::Polynomial(int degree, const double *coefficients):
        capacity(degree)
{
    this->coefficients = new double[this->capacity];
    for (int i = 0; i < degree; ++i) {
        this->coefficients[i] = coefficients[i];
    }
}

Polynomial::Polynomial(const Polynomial &that):
        capacity(that.capacity)
{
    this->coefficients = new double[this->capacity];
    for (int i = 0; i < this->capacity; ++i) {
        this->coefficients[i] = that.coefficients[i];
    }
}

Polynomial::Polynomial(Polynomial &&that):
        capacity(that.capacity)
{
    this->coefficients = new double[this->capacity];
    for (int i = 0; i < this->capacity; ++i) {
        this->coefficients[i] = that.coefficients[i];
    }

    that.capacity = 0;
    delete that.coefficients;
    that.coefficients = nullptr;
}

Polynomial::~Polynomial() {
    delete coefficients;
    coefficients = nullptr;

    capacity = 0;
}

int Polynomial::degree() const {
    for (int i = 0; i < capacity; ++i) {
        if (coefficients[capacity - i - 1] != 0) {
            return capacity - i - 1;
        }
    }
}

double Polynomial::evaluate(double x) const {
    double result = coefficients[0];

    for (int i = 1; i < capacity; ++i) {
        result = result*x + coefficients[i];
    }

    return result;
}

Polynomial Polynomial::derivative() const {
    double *newCoefficients = new double[capacity-1];

    for (int i = 0; i < capacity-1; ++i) {
        newCoefficients[i] = coefficients[i+1]*(i+1);
    }

    return Polynomial(capacity-1, newCoefficients);
}

double Polynomial::operator[](int index) const throw (out_of_range) {
    return coefficients[index];
}

Polynomial operator-(const Polynomial &a) {
    for (int i = 0; i < a.capacity; ++i) {
        a.coefficients[i] = -a.coefficients[i];
    }

    return a;
}

Polynomial operator+(const Polynomial &a, const Polynomial &b) {
    int capacity = max(a.capacity, b.capacity);
    double *result = new double[capacity];

    for (int i = 0; i < min(a.capacity, b.capacity); ++i) {
        result[i] = a.coefficients[i] + b.coefficients[i];
    }

    if (a.capacity > b.capacity) {
        for (int j = b.capacity; j < a.capacity; ++j) {
            result[j] = a.coefficients[j];
        }
    } else {
        for (int j = a.capacity; j < b.capacity; ++j) {
            result[j] = b.coefficients[j];
        }
    }

    Polynomial temp(capacity, result);
    return temp;
}

Polynomial operator-(const Polynomial &a, const Polynomial &b) {
    int capacity = max(a.capacity, b.capacity);
    double *result = new double[capacity];

    for (int i = 0; i < min(a.capacity, b.capacity); ++i) {
        result[i] = a.coefficients[i] - b.coefficients[i];
    }

    if (a.capacity > b.capacity) {
        for (int j = b.capacity; j < a.capacity; ++j) {
            result[j] = a.coefficients[j];
        }
    } else {
        for (int j = a.capacity; j < b.capacity; ++j) {
            result[j] = -b.coefficients[j];
        }
    }

    Polynomial temp(capacity, result);
    return temp;
}

Polynomial operator*(const Polynomial &a, const Polynomial &b) {
    int capacity = (a.capacity-1) + (b.capacity-1) + 1;
    double *result = new double[capacity];
    for (int i = 0; i < capacity; ++i) {
        result[i] = 0;
    }

    for (int i = 0; i < a.capacity; ++i) {
        for (int j = 0; j < b.capacity; ++j) {
            result[i+j] += a.coefficients[i]*b.coefficients[j];
        }
    }

    Polynomial temp(capacity, result);
    return temp;
}

ostream &operator<<(ostream &out, const Polynomial &what) {
    for (int i = what.capacity-1; i >= 0; --i) {
        out << what[i]
            << "*x^"
            << i;
        if (i && (what[i-1] > 0)) {
            cout << "+";
        }
    }
    out << endl;

    return out;
}
