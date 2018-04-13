//
// Created by zyngjaku on 06.04.18.
//

#include "Family.h"

Dziecko::Dziecko() {

}

Dziecko::Dziecko(string imie, string nazwisko, int wiek, string szkola) {
    this->imie = imie;
    this->nazwisko = nazwisko;
    this->wiek = wiek;
    this->szkola = szkola;
}

Dziecko::~Dziecko() {

}

string Dziecko::PokazSzkole(){
    return szkola;
}

Rodzic::Rodzic() {

}

Rodzic::Rodzic(string imie, string nazwisko, int wiek, Dziecko dziecko) {
    this->imie = imie;
    this->nazwisko = nazwisko;
    this->wiek = wiek;
    this->dziecko = dziecko;
}

Rodzic::~Rodzic() {

}

void Rodzic::ZmienSzkoleDziecku(Dziecko &obiekt, const string &nowa_szkola) {
    obiekt.szkola = nowa_szkola;
}
