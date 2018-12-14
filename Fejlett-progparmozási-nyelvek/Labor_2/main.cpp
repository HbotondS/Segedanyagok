#include <iostream>
#include <fstream>
#include <sstream>
#include <time.h>
#include <algorithm>
#include "Point.h"
#include "Functions.h"

using namespace std;

#define N 1000000

int main() {
    /**A. Feladatsor*/
    Point p1(2, 3);                     // statikusan vannak tarolva a memoriaban
    Point p2(100, 200);                 // statikus elemekre nem hasznalhato a delete operator
    cout << "p1 ("                      // forditas ideju hibat valt ki
         << p1.getX() << ", "
         << p1.getY() << ")\n";
    cout << "p2 ("
         << p2.getX() << ", "
         << p2.getY() << ")\n";

    Point* pp1 = new Point(300, 400);   // dinamikusan vannak tarolva (pointerek)
    Point* pp2 = new Point(500, 1000);
    cout << "pp1 ("                     // standard output
         << pp1->getX() << ", "
         << pp1->getY() << ")\n";
    cout << "pp2 ("
         << pp2->getX() << ", "
         << pp2->getY() << ")\n";
    delete pp1;                         // felszabaditja a memorio ezt a memoria cimet
    delete pp2;                         // mint c-ben a free

    /**B. Feladatsor*/
    // 1.
    ifstream file("../in.txt");
    string line;
    if (file.is_open()) {
        Point* points;
        if ( !(points = (Point*)malloc(4 * sizeof(Point))) ) {
            cout << "Allocation failed.\n";
            return EXIT_FAILURE;
        }
        int x, y;
        while (getline(file, line)) {
            istringstream lineStream(line);
            for (int i = 0; i < 4; ++i) {
                lineStream >> x;
                lineStream >> y;
                points[i].setX(x);
                points[i].setY(y);
            }
            if ( isSquare(points[0], points[1], points[2], points[3]) ) {
                for (int i = 0; i < 4; ++i) {
                    cout << points[i].getX() << " "
                         << points[i].getY() << " ";
                }
                cout << "is a square.\n";
            }
        }
        file.close();
        delete points;
    } else {
        cout << "The file doesn't found.\n";
    }

    // 2.
    Point* points;
    if ( !(points = (Point*)malloc(N * sizeof(Point))) ) {
        cout << "Allocation failed.\n";
        return EXIT_FAILURE;
    }
    srand(time(NULL));
    for (int i = 0; i < N; ++i) {
        points[i].setX(rand() % 2000);
        points[i].setY(rand() % 2000);
    }
    Point min[2];
    Point max[2];
    double minDist = (double)INT32_MAX;
    double maxDist = -(double)INT32_MAX;
    qsort(points, N, sizeof(Point), compareDist);
    for (int i = 0; i < 10; ++i) {
        cout << points[i].getX()
             << ", "
             << points[i].getY()
             << ": "
             << dist(points[i], Point())
             << endl;
    }
    min[0] = points[0];
    min[1] = points[1];
    minDist = dist(min[0], min[1]);
    max[0] = points[0];
    max[1] = points[N-1];
    maxDist = dist(max[0], max[1]);
    cout << "[" << min[0].getX() << ", " << min[0].getY() << "] <-> "
         << "[" << min[1].getX() << ", " << min[1].getY() << "]: "
         << minDist
         << endl;
    cout << "[" << max[0].getX() << ", " << max[0].getY() << "] <-> "
         << "[" << max[1].getX() << ", " << max[1].getY() << "]: "
         << maxDist
         << endl;

    // 3.
    sort(points, points + N, compareX);

    //4.
    Point* maxPoints = max10(points, N);
    for (int i = 0; i < 10; ++i) {
        cout << maxPoints[i].getX()
             << " "
             << maxPoints[i].getY()
             << endl;
    }
    delete points;
    return EXIT_SUCCESS;
}