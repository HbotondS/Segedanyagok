#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "Matrix.h"

using namespace std;

double median(vector<double>& v) throw(domain_error) {
    if (v.empty()) {
        throw domain_error("Empty array\n");
    } else {
        nth_element(v.begin(), v.begin() + v.size() / 2, v.end());
        if (v.size() % 2 == 0) {
            return (v[(v.size() / 2) - 1] + v[v.size() / 2]) / 2;
        } else {
            return v[v.size() / 2];
        }
    }
}

int main() {
    vector<double> array;
    array.push_back(5);
    array.push_back(2);
    array.push_back(1);
    array.push_back(3);
    array.push_back(5);
    cout << median(array)
         << endl;
    array.push_back(3);
    cout << median(array)
         << endl;

    Matrix m(4, 4);
    m.fillMatrix( 0 );
    m.printMatrix();            // Standard kimenetre
    cout<<"********************"<<endl;

    m.randomMatrix( 1, 10 );
    ofstream ofs("matrix.txt"); // fajlba iras
    if( !ofs ){
        cout<<"Fajl megnyitasi hiba"<<endl;
        return EXIT_FAILURE;
    }
    m.printMatrix( ofs );
    cout<<"Negyzetes: "<<( m.isSquare() ? "Igen":"Nem");
    Matrix mm = m;              //Milyen konstruktor hivodik? a másoló
    mm.printMatrix( ofs );
    ofs.close();

    return EXIT_SUCCESS;
}