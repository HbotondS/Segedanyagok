#include <iostream>
#include <list>
#include "List.h"

using namespace std;

bool equalList(List *list1, list<int> list2) {
    if (list2.size() == list1->size()) {
        for (int v: list2) {
            if (!list1->exists(v)) {
                return false;
            }
        }
        return true;
    } else {
        return false;
    }
}

int main() {
    List myList;
    list<int> built_inList;
    cout << myList.empty() << endl;
    myList.insertFirst(3);
    cout << myList.size() << endl;
    myList.insertFirst(2);
    myList.print();
    cout << myList.exists(3) << endl;
    myList.remove(3, List::DeleteFlag::EQUAL);
    myList.insertFirst(4);
    myList.print();
    built_inList.push_front(2);
    built_inList.push_front(4);
    for (int v: built_inList) {
        cout << v << " ";
    }
    cout << endl;
    cout << "The lists is "
         << (equalList(&myList, built_inList) ? "equal.\n" : "not equal.\n" );
    built_inList.push_front(3);
    built_inList.remove(3);
    return 0;
}