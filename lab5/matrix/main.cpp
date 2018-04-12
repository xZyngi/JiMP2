//
// Created by zyngjaku on 06.04.18.
//

#include <iostream>
#include "Matrix.h"

using namespace std;

int main(){
    Matrix m1("[1 2 3;3 4 5; 2 3 4]");
    Matrix m2("[3 2 1; 5 4 3; 7 6 5]");

    cout << "Macierz pierwsza: " << m1.print() << endl;
    cout << "Macierz druga: " << m2.print() << endl;

    cout << "Dodawanie" << (m1.add(m2)).print() << endl;
    cout << "Odejmowanie" << (m1.sub(m2)).print() << endl;
    cout << "Mnożenie" << (m1.mul(m2)).print() << endl;
    cout << "Dzielenie" << (m1.div(m2)).print() << endl;
    cout << "Potęgowanie" << (m1.pow(2)).print() << endl;
    cout << "Potęgowanie" << (m2.pow(2)).print() << endl;

    return 0;
}