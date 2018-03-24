//
// Created by kamila on 23.03.18.
//

#ifndef JIMP_EXERCISES_SQUARE_H
#define JIMP_EXERCISES_SQUARE_H

#include <math.h>
#include <iostream>
#include <utility>

using namespace std;

class Point {
public:
    Point();

    Point(double x, double y);

    ~Point();

    void ToString(std::ostream *out) const;
    double Distance(const Point &other) const;

    double GetX() const;
    double GetY() const;

    void SetX(double x);
    void SetY(double y);

private:
    double x_, y_;
};


#endif //JIMP_EXERCISES_SQUARE_H
