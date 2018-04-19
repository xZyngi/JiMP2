//
// Created by zyngi on 18.04.18.
//

#ifndef JIMP_EXERCISES_SHAPE_H
#define JIMP_EXERCISES_SHAPE_H

#include <iostream>

using namespace std;

class Kolo {
public:
    Kolo(double x, double y, double r) {
        x_ = x;
        y_ = y;
        r_ = r;
    }

    void wyswietl(){
        cout << x_ << endl << y_ << endl << r_ << endl;
    }

    virtual double pole();
private:
    double x_;
    double y_;
    double r_;
};

class Kula : public Kolo {
public:
    Kula(double x, double y, double z, double r) : Kolo(x, y, r){
        z_ = z;

        Kolo::wyswietl();
        cout << endl;
        obliczPola();
    }

    void wyswietl(){
        Kolo::wyswietl();
        cout << z_ << endl;
    }

    void obliczPola(){
        cout << Kolo::pole() << endl;
        cout << pole() << endl;
    }

    double pole();
private:
    double z_;
};

#endif //JIMP_EXERCISES_SHAPE_H
