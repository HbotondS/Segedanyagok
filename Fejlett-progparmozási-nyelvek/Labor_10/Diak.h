//
// Created by Boti on 12/20/2018.
//

#ifndef LABOR_10_DIAK_H
#define LABOR_10_DIAK_H

#include <string>

using namespace std;

class Diak {
private:
    string vnev;
    string knev;
    double atlag;

public:
    Diak(string, string = "", double = 0);
    double getAtlag();
    string getKnev();
    string getVnev();

    friend ostream& operator<<(ostream&, Diak&);
    friend istream& operator>>(istream&, Diak&);
    friend bool operator<(const Diak&, const Diak&);
};


#endif //LABOR_10_DIAK_H
