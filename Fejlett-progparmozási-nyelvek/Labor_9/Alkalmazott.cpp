//
// Created by Boti on 4/16/2018.
//

#include "Alkalmazott.h"

Alkalmazott::Alkalmazott(string vezetekNev, string keresztNev, int szuletesiEv, string munkakor):
        Szemely(vezetekNev, keresztNev, szuletesiEv), munkakor(munkakor)
{
}

void Alkalmazott::print(ostream &os) const{
    os << keresztNev
       << " " << vezetekNev
       << " " << szuletesiEv
       << " " << munkakor
       << endl;
}
