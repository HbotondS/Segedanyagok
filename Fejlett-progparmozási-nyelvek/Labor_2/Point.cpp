//
// Created by Boti on 2/23/2018.
//

#include "Point.h"

Point::Point(int x, int y) {
    if (0 <= x && x <= 2000) {
        this->x = x;
    } else {
        this->x = 0;
    }

    if (0 <= y && y <= 2000) {
        this->y = y;
    } else {
        this->y = 0;
    }
}

int Point::getX() const {
    return x;
}

int Point::getY() const {
    return y;
}

void Point::setX(int x) {
    if (0 <= x && x <= 2000) {
        this->x = x;
    }
}

void Point::setY(int y) {
    if (0 <= y && y <= 2000) {
        this->y = y;
    }
}

void Point::move(int nx, int ny) {
    if (0 <= nx && nx <= 2000 && 0 <= ny && ny <= 2000) {
        this->x = nx;
        this->y = ny;
    }
}