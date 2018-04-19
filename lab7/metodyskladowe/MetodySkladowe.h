//
// Created by zyngi on 18.04.18.
//

#ifndef JIMP_EXERCISES_METODYSKLADOWE_H
#define JIMP_EXERCISES_METODYSKLADOWE_H

#include <iostream>

using namespace std;

class LiczbaRzeczywista{
protected:
    double re;
public:
    LiczbaRzeczywista(double r);
    void wypisz();
    void powitaj();

    LiczbaRzeczywista operator+(const LiczbaRzeczywista& r);
};

class LiczbaZespolona : public LiczbaRzeczywista{
protected:
    double im;
public:
    LiczbaZespolona(double re, double i):LiczbaRzeczywista(re){im=i;}
    void wypisz();
};

#endif //JIMP_EXERCISES_METODYSKLADOWE_H
