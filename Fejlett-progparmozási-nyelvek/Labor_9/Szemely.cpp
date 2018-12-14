//
// Created by Boti on 4/16/2018.
//

#include "Szemely.h"

Szemely::Szemely(string vezetekNev, string keresztNev, int szuletesiEv):
        vezetekNev(vezetekNev), keresztNev(keresztNev), szuletesiEv(szuletesiEv)
{
}

void Szemely::print(ostream &os) const {
    os << keresztNev
       << " " << vezetekNev
       << " " << szuletesiEv
       << endl;
}
