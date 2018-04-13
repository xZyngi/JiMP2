//
// Created by kamila on 23.03.18.
//

#ifndef JIMP_EXERCISES_SQUARE_H
#define JIMP_EXERCISES_SQUARE_H

#include <math.h>
#include <iostream>
#include <utility>

#include <iostream>
#include <cmath>
#include <ostream>

using namespace std;

namespace geometry {
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

    class Square {
    public:
        Square();

        Square(Point p1, Point p2, Point p3, Point p4);

        ~Square();

        double Circumference();

        double Area();

        void Setpoint(Point p);

    private:
        Point p1_, p2_, p3_, p4_;

    };
}

#endif //JIMP_EXERCISES_SQUARE_H
