//
// Created by Boti on 6/25/2018.
//

#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H

#include <iostream>
#include <stdexcept>

using namespace std;

class Queue {
public:
    Queue(int size = 0, int maxSize = 10000);
    // fills the queue with numbers stored int the filename file
    Queue(const char* filename);
    // copy constructor
    Queue(const Queue&);
    // move constructor
    Queue(Queue&&);
    // destructor
    ~Queue();

    // push operation to insert an element to the queue
    void push(double d);
    // pop operation to remove an element from the queue
    void pop();
    // prints the queue
    friend ostream &operator<<(ostream &, const Queue &);
    // only assign if the queues have the same length
    Queue &operator=(const Queue &) throw(out_of_range);
    double operator[](int index) throw(out_of_range);
    // returns a string that stores the elements of the queue without spaces
    string toString();
    // sets the size of the queue to newSize and remove the extra elements
    void trimToSize(int newSize);

private:
    int size;
    int maxSize;
    double* elements;
};


#endif //QUEUE_QUEUE_H
