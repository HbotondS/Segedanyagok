//
// Created by Boti on 2/28/2018.
//

#include <iostream>
#include <time.h>
#include <algorithm>
#include <math.h>
#include "PontHalmaz.h"

void PontHalmaz::clacDist() {
    for (int i = 0; i < numberOfPoints; ++i) {
        for (int j = i+1; j < numberOfPoints; ++j) {
            distance.push_back(sqrt(pow(points.at(j).getX() - points.at(i).getX(), 2) +
                                    pow(points.at(j).getY() - points.at(i).getY(), 2)));
        }
    }
}

PontHalmaz::PontHalmaz(int numberOfPoints) {
    this->numberOfPoints = numberOfPoints;
    srand(time(NULL));
    for (int i = 0; i < numberOfPoints; ++i) {
        this->points.push_back(Point(rand() % 1500, rand() % 1500));
    }
    this->clacDist();
}

double PontHalmaz::maxDist() const {
    return *max_element(distance.begin(), distance.end());
}

double PontHalmaz::minDist() const {
    return *min_element(distance.begin(), distance.end());
}

int PontHalmaz::numOfDist() const {
    return distance.size();
}

void PontHalmaz::printPoints() const {
    for (auto v: points) {
        cout << v.getX() << " "
             << v.getY() << " "
             << endl;
    }
}

void PontHalmaz::printDist() const {
    for (auto v: distance) {
        cout << v << " ";
    }
    cout << endl;
}

bool compareX(Point a, Point b) {
    return a.getX() < b.getX();
}

void PontHalmaz::sortX() {
    sort(points.begin(), points.end(), compareX);
}

bool compareY(Point a, Point b) {
    return a.getX() < b.getX();
}

void PontHalmaz::sortY() {
    sort(points.begin(), points.end(), compareY);
}

void PontHalmaz::sortDist() {
    sort(distance.begin(), distance.end());
}

int PontHalmaz::numberOfDistinctDist() const {
    return distance.size();
}
