//
// Created by zyngjaku on 06.04.18.
//

#ifndef JIMP_EXERCISES_FAMILY_H
#define JIMP_EXERCISES_FAMILY_H

#include <iostream>
#include <string>

using namespace std;

class Rodzic;

class Dziecko {
public:
    friend class Rodzic;

    Dziecko();
    Dziecko(string imie, string nazwisko, int wiek, string szkola);

    ~Dziecko();

    string PokazSzkole();
private:
    string imie;
    string nazwisko;
    int wiek;
    string szkola;
};

class Rodzic {
public:
    Rodzic();
    Rodzic(string imie, string nazwisko, int wiek, Dziecko dziecko);

    ~Rodzic();

    void ZmienSzkoleDziecku(Dziecko &obiekt, const string &nowa_szkola);
private:
    string imie;
    string nazwisko;
    int wiek;
    Dziecko dziecko;
};

#endif //JIMP_EXERCISES_FAMILY_H
