#include <iostream>
#include "Queue.h"

int main() {
    Queue queue;
    queue.push(3.2);
    queue.push(1.2);
    queue.push(2.2);
    cout << queue;
    return 0;
}