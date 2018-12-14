//
// Created by Boti on 2/23/2018.
//

#include <iostream>
#include "Functions.h"
#include <math.h>

using namespace std;

double dist(Point p1, Point p2) {
    return sqrt(pow(p2.getX() - p1.getX(), 2) +
            pow(p2.getY() - p1.getY(), 2));
}

bool isSquare(Point p1, Point p2, Point p3, Point p4) {
    double d1 = dist(p1, p2);
    double d2 = dist(p2, p3);
    double d3 = dist(p3, p4);
    double d4 = dist(p4, p1);
    double d5 = dist(p1, p3);
    double d6 = dist(p2, p4);
    return d1 == d2 && d1 == d3 && d1 == d4 && d5 == d6;
}

int compareDist(const void* a, const void* b) {
    Point* p1 = (Point*) a;
    Point* p2 = (Point*) b;
    double dist1 = dist(Point(p1->getX(), p1->getY()), Point());
    double dist2 = dist(Point(p2->getX(), p2->getY()), Point());
    if ( dist1 == dist2 ) {
        return 0;
    } else {
        if ( dist1 < dist2 ) {
            return -1;
        } else {
            return 1;
        }
    }
}

bool compareX(Point a, Point b) {
    return a.getX() < b.getX();
}

Point* max10(Point* points, int numberOfElements) {
    Point* localPoints = points;
    qsort(localPoints, numberOfElements, sizeof(Point), compareDist);
    Point* maxPoints;
    for (int i = 0; i < 10; ++i) {
        maxPoints[i] = localPoints[numberOfElements - 10 + i];
    }
    return maxPoints;
}