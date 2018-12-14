//
// Created by Boti on 2/23/2018.
//

#ifndef LABOR_3_FUNCTIONS_H
#define LABOR_3_FUNCTIONS_H

#include "Point.h"

double dist(Point p1, Point p2);
bool isSquare(Point p1, Point p2, Point p3, Point p4);
int compareDist(const void* a, const void* b);
bool compareX(Point a, Point b);
Point* max10(Point* points, int numberOfElements);


#endif //LABOR_3_FUNCTIONS_H
