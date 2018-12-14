//
// Created by Boti on 3/15/2018.
//

#include <iostream>
#include "List.h"

using namespace std;

List::List() {
    first = nullptr;
}

List::~List() {
    while (first != nullptr) {
        Node* next = first->next;
        delete first;
        first = next;
    }
}

bool List::exists(int d) const {
    Node* actualNode = first;
    while (actualNode != nullptr) {
        if (actualNode->value == d) {
            return true;
        } else {
            actualNode = actualNode->next;
        }
    }
    return false;
}

int List::size() const {
    return nodeCounter;
}

bool List::empty() const {
    return nodeCounter == 0;
}

void List::insertFirst(int d) {
    first = new Node(d, first);
    ++nodeCounter;
}

void List::remove(int d, List::DeleteFlag df) {
    switch (df) {
        case DeleteFlag::LESS :
            if (first->value < d) {
                first = first->next;
                --nodeCounter;
                return;
            }
            break;
        case DeleteFlag::GREATER :
            if (first->value > d) {
                first = first->next;
                --nodeCounter;
                return;
            }
            break;
        case DeleteFlag::EQUAL :
            if (first->value == d) {
                first = first->next;
                --nodeCounter;
                return;
            }
            break;
    }

    Node* previous = first;
    Node* current = first->next;
    while (previous != nullptr && current != nullptr) {
        switch (df) {
            case DeleteFlag::LESS :
                if (current->value < d) {
                    Node* temp = current;
                    previous->next = current->next;
                    delete(temp);
                    --nodeCounter;
                    return;
                }
                break;
            case DeleteFlag::GREATER :
                if (current->value > d) {
                    Node* temp = current;
                    previous->next = current->next;
                    delete(temp);
                    --nodeCounter;
                    return;
                }
                break;
            case DeleteFlag::EQUAL :
                if (current->value == d) {
                    Node* temp = current;
                    previous->next = current->next;
                    delete(temp);
                    --nodeCounter;
                    return;
                }
                break;
        }
        previous = current;
        current = current->next;
    }
}

void List::print() const {
    Node* actualNode = first;
    while (actualNode != nullptr) {
        cout << actualNode->value << " ";
        actualNode = actualNode->next;
    }
    cout << endl;
}
