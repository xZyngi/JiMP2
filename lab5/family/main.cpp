//
// Created by zyngjaku on 06.04.18.
//

#include "Family.h"

int main(){

    Dziecko d("Josh", "Kappa", 18, "Podstawowa");

    cout << d.PokazSzkole() << endl;

    Rodzic r("Abc", "Xyz", 40, d);

    r.ZmienSzkoleDziecku(d, "Średnia");

    cout << d.PokazSzkole() << endl;

    return 0;
}
