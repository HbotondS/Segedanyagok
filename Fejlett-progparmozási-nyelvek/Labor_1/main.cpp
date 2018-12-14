#include <iostream>
#include "functions.h"

using namespace std;

int main() {
    cout << "A 13-ban ennyi egyes bit van: "
         << countBits(13) << endl;
    cout << setBit(1, 3) << endl;
    int szam = 1;

    cout << setBit2(szam, 3) << endl;
    double array[] = {1.0, 2.0, 3.0};
    cout << "A tomb atlaga: "
         << mean(array, 3) << endl;
    cout << "A tomb szorasa: "
         << stddev(array, 3) << endl;
    double a[] = {2.5};
    double * mx;
    if ( !(mx = (double *)malloc((3) * sizeof(double))) ) {
        cout << "Allocation failed" << endl;
    }
    mx = max2(a, 1);
    cout << "A tomb ket legnagyobb eleme: ";
    for (int i = 0; i < 2; ++i) {
        cout << mx[i] << " ";
    }
    cout << endl << "A tomb ket legnagyobb eleme: ";
    mx = max2(array, 3);
    for (int i = 0; i < 2; ++i) {
        cout << mx[i] << " ";
    }
    cout << endl;

    string line;
    getline(cin, line);
    cout << "Minden szo nagybetuvel: "
         << capitalizeWords(line) << endl;
    string codedString = code(line);
    cout << line
         << " kodolva: "
         << codedString << endl;
    cout << codedString
         << " dekodolva: "
         << decode(codedString) << endl;
    cout << line
         << " szobol all: "
         << splitText(line) << endl;
    return 0;
}