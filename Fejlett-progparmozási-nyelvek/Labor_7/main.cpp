#include <iostream>
#include "Polynomial.h"

using namespace std;

int main() {
    double a[] = {1, 1, 2, 1};
    Polynomial pol1(4, a);
    cout << pol1.degree() << endl;

    double b[] = {2, 2};
    Polynomial pol2(2, b);
    cout << pol2.evaluate(1)
         << " "
         << pol1.evaluate(1) << endl;
    cout << pol1
         << pol1.derivative();

    cout << pol1 - pol2;

    cout << pol1 * pol2;
    return 0;
}