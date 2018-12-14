//
// Created by Boti on 4/16/2018.
//

#ifndef LABOR_9_MANAGER_H
#define LABOR_9_MANAGER_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Alkalmazott.h"

class Manager: public Alkalmazott {
private:
    vector<Alkalmazott *> beosztottak;

public:
    Manager(string vezetekNev, string keresztNev, int szuletesiEv, string munkakor): Alkalmazott(vezetekNev, keresztNev, szuletesiEv, munkakor){}
    void addAlkalmazott(Alkalmazott *);
    void deleteAlkalmazott(Alkalmazott *);
    int beosztottakSzama() const;
    void print(ostream &) const;
};


#endif //LABOR_9_MANAGER_H
