//
// Created by Boti on 12/20/2018.
//

#ifndef LABOR_10_FELVETELI_H
#define LABOR_10_FELVETELI_H

#include <vector>
#include "Diak.h"

using namespace std;

class Felveteli {
private:
    int helyekSzama;
    vector<Diak> diakok;

public:
    Felveteli(int);
    void beiratkozas(Diak);
    void rendezesABC();
    void rendezesAtlag();
    void kiiratas(ostream&);
    void bejutottak(ostream&);
};


#endif //LABOR_10_FELVETELI_H
