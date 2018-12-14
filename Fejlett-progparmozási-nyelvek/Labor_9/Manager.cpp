//
// Created by Boti on 4/16/2018.
//

#include "Manager.h"

void Manager::addAlkalmazott(Alkalmazott *alk) {
    beosztottak.push_back(alk);
}

void Manager::deleteAlkalmazott(Alkalmazott *alk) {
    beosztottak.erase(remove(begin(beosztottak), end(beosztottak), alk), end(beosztottak));
}

int Manager::beosztottakSzama() const {
    return beosztottak.size();
}

void Manager::print(ostream &os) const {
    Alkalmazott::print(os);
}
