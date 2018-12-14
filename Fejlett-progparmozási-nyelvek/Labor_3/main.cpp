#include <iostream>
#include <algorithm>
#include <vector>
#include "PontHalmaz.h"

using namespace std;

int main() {
    int n = 2;
    cout<<"Pontok\tMinTav\tMaxTav\t#tavolsagok\t#kulonbozotavolsagok"<<endl;
    for (int i = 0; i < 12; ++i) {
        PontHalmaz ph(n);
        cout << n << "\t" << ph.minDist() << "\t" << ph.maxDist() << "\t";
        cout << ph.numOfDist() << "\t" << ph.numberOfDistinctDist() << endl;
        n <<= 1;
    }
    return EXIT_SUCCESS;
}