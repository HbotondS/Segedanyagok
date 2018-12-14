//
// Created by Boti on 4/16/2018.
//

#ifndef LABOR_9_SZEMELY_H
#define LABOR_9_SZEMELY_H

#include <iostream>
#include <string>

using namespace std;

class Szemely {
protected:
    string vezetekNev;
    string keresztNev;
    int szuletesiEv;

public:
    Szemely(string, string, int);
    void print(ostream &) const;
};


#endif //LABOR_9_SZEMELY_H
