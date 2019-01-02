//
// Created by Boti on 12/20/2018.
//

#include "Diak.h"

using namespace std;

Diak::Diak(string vnev, string knev, double atlag) {
    this->vnev = vnev;
    this->knev = knev;
    this->atlag = atlag;
}

double Diak::getAtlag() {
    return this->atlag;
}

string Diak::getKnev() {
    return this->knev;
}

string Diak::getVnev() {
    return this->vnev;
}

ostream &operator<<(ostream &os, Diak &diak) {
    os << diak.vnev << diak.knev;
    return os;
}

istream &operator>>(istream &is, Diak &diak) {
    is >> diak.vnev >> diak.knev;
    return is;
}

bool operator<(const Diak &diak1, const Diak &diak2) {
    if (diak1.vnev.compare(diak2.vnev) < 0) {
        return true;
    } else {
        return false;
    }
}


