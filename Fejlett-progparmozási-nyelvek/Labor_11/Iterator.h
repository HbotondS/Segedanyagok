//
// Created by Boti on 5/8/2018.
//

#ifndef LABOR_11_ITERATOR_H
#define LABOR_11_ITERATOR_H


#include "OrderedList.h"

template<class T, class LessComp=less<T>, class Equal=equal_to<T> >
class Iterator {
private:
    OrderedList<T, LessComp, Equal>& list;
    typename OrderedList<T, LessComp, Equal>::Node *act;

public:
    Iterator(OrderedList<T, LessComp, Equal>&);
    bool hasNext();
    T next();
};

template<class T, class LessComp, class Equal>
Iterator<T, LessComp, Equal>::Iterator(OrderedList<T, LessComp, Equal> &list): list(list) {
    act = list.first;
}

template<class T, class LessComp, class Equal>
bool Iterator<T, LessComp, Equal>::hasNext() {
    return act->next != nullptr;
}

template<class T, class LessComp, class Equal>
T Iterator<T, LessComp, Equal>::next() {
    OrderedList::Node *temp = act;
    act = act->next;
    return temp->value;
}


#endif //LABOR_11_ITERATOR_H
