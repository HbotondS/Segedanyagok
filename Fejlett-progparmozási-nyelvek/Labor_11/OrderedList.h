//
// Created by Boti on 5/8/2018.
//

#ifndef LABOR_11_ORDEREDLIST_H
#define LABOR_11_ORDEREDLIST_H

#include <iostream>

using namespace std;

template<class T, class LessComp = less<T>, class Equal = equal_to<T> >
class OrderedList {
//    template<class T, class LessComp = less<T>, class Equal = equal_to<T> >
//    friend class Iterator<T, LessComp, Equal>;
    friend class Iterator;

public:
    class Node {
    public:
        T value;
        Node *next;

        Node(T v, Node *n) : value(v), next(n) {}
    };

    OrderedList() : numElements(0), first(nullptr) {}

    ~OrderedList();

    bool isEmpty() {
        return numElements;
    }

    void insert(const T &value);

    void remove(T &value);

    int size() const {
        return numElements;
    }

    bool find(T &value) const;

    void listItems(ostream &os);


private:
    Node *first;
    int numElements;
};

template<class T, class LessComp, class Equal>
OrderedList<T, LessComp, Equal>::~OrderedList() {
    Node *actualNode = first;
    Node *nextNode = first->next;
    do {
        delete (actualNode);
        actualNode = nextNode;
        nextNode = nextNode->next;
    } while (actualNode == nullptr);
    numElements = 0;
}

template<class T, class LessComp, class Equal>
void OrderedList<T, LessComp, Equal>::insert(const T &value) {
    if (first == nullptr) {
        first = new Node(value, nullptr);
        ++numElements;
    } else {
        Node *actualNode = first;
        while (LessComp()(actualNode->value, value)) {
            actualNode = actualNode->next;
        }
        actualNode = new Node(value, actualNode);
        ++numElements;
    }
}

template<class T, class LessComp, class Equal>
void OrderedList<T, LessComp, Equal>::remove(T &value) {
    if (!find(value)) {
        cout << "This element doesn't exist" << endl;
        return;
    }
    Node *actualNode = first;
    Node *save = actualNode;
    for (int i = 0; i < numElements; ++i) {
        if (actualNode->value == value) {
            if (i == 0) {
                // delete first
                first = actualNode->next;
                delete actualNode;
                --numElements;
                break;
            } else {
                if (i + 1 == numElements) {
                    // delete last
                    delete actualNode;
                    --numElements;
                    break;
                } else {
                    // delete actualNode
                    Node *current = save;
                    Node *previous = current;
                    current = current->next;
                    previous->next = current->next;
                    --numElements;
                    break;
                }
            }
        }
        save = actualNode;
        actualNode = actualNode->next;
    }
}

template<class T, class LessComp, class Equal>
bool OrderedList<T, LessComp, Equal>::find(T &value) const {
    bool result = false;
    Node *actualNode = first;
    while (actualNode != nullptr) {
        if (actualNode->value == value) {
            result = true;
            break;
        }
        actualNode = actualNode->next;
    }
    return result;
}

template<class T, class LessComp, class Equal>
void OrderedList<T, LessComp, Equal>::listItems(ostream &os) {
    Node *actualNode = first;
    while (actualNode != nullptr) {
        os << actualNode->value << " ";
        actualNode = actualNode->next;
    }
    os << endl;
}


#endif //LABOR_11_ORDEREDLIST_H
