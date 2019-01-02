#include <iostream>
#include <fstream>
#include "Diak.h"
#include "Felveteli.h"

using namespace std;

int main() {
    Diak diak1("pityi", "palko", 5.6);
    Diak diak2("nagy", "moricka", 6);
    Diak diak3("Pista", "ba");

    Felveteli informatikaFelveteli(2);
    informatikaFelveteli.beiratkozas(diak1);
    informatikaFelveteli.beiratkozas(diak2);
    informatikaFelveteli.beiratkozas(diak3);
    informatikaFelveteli.rendezesABC();
    informatikaFelveteli.kiiratas(cout);

    informatikaFelveteli.rendezesAtlag();
    informatikaFelveteli.kiiratas(cout);

    ofstream kiFile;
    kiFile.open("ki.txt");
    informatikaFelveteli.bejutottak(kiFile);
    kiFile.close();
    return 0;
}