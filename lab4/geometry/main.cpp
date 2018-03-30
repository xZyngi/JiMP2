//
// Created by kamila on 23.03.18.
//

#include <memory>
#include <vector>
#include <iostream>
#include <sstream>
#include "Square.h"

using namespace std;

int main() {

    Point p1(-1, 0);
    Point p2(0, -1);
    Point p3(0, 1);
    Point p4(1, 0);

    cout << p1.GetX() << " " << p1.GetY() << endl;
    cout << p2.GetX() << " " << p2.GetY() << endl;
    cout << p3.GetX() << " " << p3.GetY() << endl;
    cout << p4.GetX() << " " << p4.GetY() << endl;

    Square s(p1, p2, p3, p4);
    cout << s.Circumference() << endl;
    cout << s.Area() << endl;

    return 0;
}