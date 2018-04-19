//
// Created by zyngi on 18.04.18.
//

#include "Shape.h"

double Kolo::pole() {
    return 3.14*r_*r_;
}

double Kula::pole() {
    return 4*Kolo::pole();
}
