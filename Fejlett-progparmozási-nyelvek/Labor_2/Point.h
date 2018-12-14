//
// Created by Boti on 2/23/2018.
//

#ifndef LABOR_3_POINT_H
#define LABOR_3_POINT_H

class Point {
private:
    int x, y;

public:
    Point(int x = 0, int y = 0);
    int getX() const;
    int getY() const;
    void setX(int x);
    void setY(int y);
    void move(int nx, int ny);
};

#endif //LABOR_3_POINT_H
