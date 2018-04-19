//
// Created by zyngi on 18.04.18.
//

#include "MetodySkladowe.h"

LiczbaRzeczywista::LiczbaRzeczywista(double r) {
    re=r;
}

void LiczbaRzeczywista::wypisz() {
    cout << re << endl;
}

void LiczbaRzeczywista::powitaj() {
    cout << "Czesc!" << endl;
}

LiczbaRzeczywista LiczbaRzeczywista::operator+(const LiczbaRzeczywista &r) {
    LiczbaRzeczywista rr(re+r.re);
    return rr;
}

void LiczbaZespolona::wypisz() {
    cout << re << " + " << im << "i" << endl;
}
