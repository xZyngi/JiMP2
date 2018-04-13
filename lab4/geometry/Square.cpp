//
// Created by kamila on 23.03.18.
//

#include "Square.h"

using ::std::ostream;
using ::std::endl;
using ::std::pow;
using ::std::sqrt;

namespace geometry {
    Point::Point() {

    }

    Point::Point(double x, double y) {
        x_ = x;
        y_ = y;
    }

    Point::~Point() {

    }

    void Point::ToString(std::ostream *out) const {
        (*out) << "(" << GetX() << ";" << GetY() << ")";
    }

    double Point::Distance(const Point &other) const {
        return sqrt(pow(GetX() - other.GetX(), 2) + pow(GetY() - other.GetY(), 2));
    }

    double Point::GetX() const {
        return x_;
    }

    double Point::GetY() const {
        return y_;
    }

    void Point::SetX(double x) {
        x_ = x;
    }

    void Point::SetY(double y) {
        y_ = y;
    }

    Square::Square() {

    }

    Square::Square(Point p1, Point p2, Point p3, Point p4) {
        p1_ = p1;
        p2_ = p2;
        p3_ = p3;
        p4_ = p4;
    }

    Square::~Square() {

    }

    bool isSquare(Point p1, Point p2, Point p3, Point p4) {

        double distance_2 = p1.Distance(p2);
        double distance_3 = p1.Distance(p3);
        double distance_4 = p1.Distance(p4);

        if (distance_2 == distance_3)
            return (p2.Distance(p4) == p3.Distance(p4) && p2.Distance(p4) == distance_2);

        if (distance_3 == distance_4)
            return (p2.Distance(p3) == p2.Distance(p4) && p2.Distance(p3) == distance_3);

        if (distance_2 == distance_4)
            return (p2.Distance(p3) == p3.Distance(p4) && p2.Distance(p3) == distance_2);

        return false;
    }

    double Square::Circumference() {

        if (isSquare(p1_, p2_, p3_, p4_)) {
            if (p1_.Distance(p2_) <= p1_.Distance(p3_))
                return 4 * (p1_.Distance(p2_));
            else if (p1_.Distance(p3_) <= p1_.Distance(p4_))
                return 4 * (p1_.Distance(p2_));
        }

        return 0;
    }

    double Square::Area() {

        if (isSquare(p1_, p2_, p3_, p4_)) {
            if (p1_.Distance(p2_) <= p1_.Distance(p3_))
                return (p1_.Distance(p2_) * p1_.Distance(p2_));
            else if (p1_.Distance(p3_) <= p1_.Distance(p4_))
                return (p1_.Distance(p2_) * p1_.Distance(p2_));
        }

        return 0;
    }

    void Square::Setpoint(Point p) {

    }
}