//
// Created by Boti on 6/25/2018.
//

#include "Queue.h"

Queue::Queue(int size, int maxSize):size(size), maxSize(maxSize) {
    elements = new double[maxSize];
}

Queue(const char* filename) {
    ifstream ifs(filename);
    int n = 0;
    ifs >> n;
    for (int i = 0; i < n; ++i) {
        ifs >> elements[i];
    }
    size = n;
}

Queue::Queue(const Queue &that):size(that.size), maxSize(that.maxSize) {
    this->elements = new double[this->size];
    for (int i = 0; i < this->size; ++i) {
        this->elements[i] = that.elements[i];
    }
}

Queue::Queue(Queue &&that):size(that.size), maxSize(that.maxSize) {
    this->elements = new double[this->size];
    for (int i = 0; i < this->size; ++i) {
        this->elements[i] = that.elements[i];
    }

    that.size = 0;
    that.maxSize = 0;
    delete[] that.elements;
    that.elements = nullptr;
}

Queue::~Queue() {
    size = 0;
    maxSize = 0;
    delete[] elements;
    elements = nullptr;
}

void Queue::push(double d) {
    elements[size++] = d;
}

void Queue::pop() {
    for (int i = 0; i < size-1; ++i) {
        elements[i] = elements[i+1];
    }
    --size;
}

ostream &operator<<(ostream &os, const Queue &that) {
    for (int i = 0; i < that.size; ++i) {
        os << that.elements[i] << " ";
    }
}

Queue &Queue::operator=(const Queue &that) {
    if (this->size == that.size) {
        if (&that != this) {
            for (int i = 0; i < size; ++i) {
                this->elements[i] != that.elements[i];
            }

            return *this;
        }
    } else {
        throw out_of_range("the sizes are not the same");
    }
}

double Queue::operator[](int index) {
    if (index < size) {
        return elements[index];
    } else {
        throw out_of_range("the index is too big");
    }
}

string Queue::toString() {
    string str;
    for (int i = 0; i < size; ++i) {
        str += to_string(elements[i]);
    }
    return str;
}

void Queue::trimToSize(int newSize) {
    if (newSize < size) {
        for (int i = newSize; i < size; ++i) {
            elements[i] = 0;
        }
    }
    size = newSize;
}
