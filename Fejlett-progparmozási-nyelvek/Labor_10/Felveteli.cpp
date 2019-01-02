//
// Created by Boti on 12/20/2018.
//

#include <iostream>
#include "Felveteli.h"

using namespace std;

Felveteli::Felveteli(int helyekSzama) {
    this->helyekSzama = helyekSzama;
}

void Felveteli::beiratkozas(Diak diak) {
    if (diakok.size() == helyekSzama) {
        cout<<"A helyek beteltek\n";
        return;
    } else {
        diakok.push_back(diak);
    }
}

void Felveteli::rendezesABC() {
    while(1) {
        bool csere = false;

        for (int i = 0; i < diakok.size()-1; ++i) {
            if (diakok[i+1] < diakok[i]) {
                Diak temp = diakok[i+1];
                diakok[i+1] = diakok[i];
                diakok[i] = temp;
                csere = true;
            }
        }

        if (!csere) {
            break;
        }
    }
}

void Felveteli::rendezesAtlag() {
    while(1) {
        bool csere = false;

        for (int i = 0; i < diakok.size()-1; ++i) {
            if (diakok[i].getAtlag() > diakok[i+1].getAtlag()) {
                Diak temp = diakok[i+1];
                diakok[i+1] = diakok[i];
                diakok[i] = temp;
                csere = true;
            }
        }

        if (!csere) {
            break;
        }
    }
}

void Felveteli::kiiratas(ostream &os) {
    for (int i = 0; i < diakok.size(); ++i) {
        os << diakok[i] << endl;
    }
}

void Felveteli::bejutottak(ostream &os) {
    for (int i = 0; i < diakok.size(); ++i) {
        if (diakok[i].getAtlag() >= 5) {
            os << diakok[i] << endl;
        }
    }
}
