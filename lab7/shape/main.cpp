//
// Created by zyngi on 18.04.18.
//

#include <iostream>
#include "Shape.h"

using namespace std;

int main(){

    Kolo *k = new Kula(0,0,0,10);
    cout << k->pole() << endl;
    delete k;

    return 0;
}