//
// Created by Boti on 2/28/2018.
//

#ifndef LABOR_3_PONTHALMAZ_H
#define LABOR_3_PONTHALMAZ_H

#include "Point.h"
#include <vector>

using namespace std;


class PontHalmaz {
    vector<Point> points;
    int numberOfPoints;
    vector<double> distance;    // the distance between the points

    void clacDist();

public:
    PontHalmaz( int numberOfPoints = 100 );     // generate random points
                                                // end calculate the distance
    double maxDist() const;
    double minDist() const;

    int numOfDist() const;

    void printPoints() const;
    void printDist() const;

    void sortX();
    void sortY();
    void sortDist();

    int numberOfDistinctDist() const;
};


#endif //LABOR_3_PONTHALMAZ_H
