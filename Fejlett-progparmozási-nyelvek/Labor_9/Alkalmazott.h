//
// Created by Boti on 4/16/2018.
//

#ifndef LABOR_9_ALKALMAZOTT_H
#define LABOR_9_ALKALMAZOTT_H

#include <iostream>
#include <string>
#include "Szemely.h"

class Alkalmazott: public Szemely {
protected:
    string munkakor;

public:
    Alkalmazott(string, string, int, string);
    void print(ostream &) const;
};


#endif //LABOR_9_ALKALMAZOTT_H
