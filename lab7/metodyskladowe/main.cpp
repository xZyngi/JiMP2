//
// Created by zyngi on 18.04.18.
//

#include <iostream>
#include "MetodySkladowe.h"

using namespace std;

int main(){
    LiczbaRzeczywista a(12);
    LiczbaZespolona b(23,5);

    a.powitaj();         //Czesc!
    a.wypisz();          //12
    (a+a).wypisz();      //24

    b.powitaj();         //Czesc!
    b.wypisz();          //23 + 5I


    (b+b).wypisz();      //Co się wypisze?
}