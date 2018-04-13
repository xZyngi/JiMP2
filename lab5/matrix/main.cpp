//
// Created by kamila on 10.04.18.
//

#include <iostream>
#include "Matrix.h"
using std::cout;
using std::endl;

using namespace algebra;

int main(int argc, char* argv[]){
    Matrix m1{{1.0i, 0., 0.}, {0., 1.0i, 0.}};
    Matrix m2{{7. + 1.0i, 0.}, {0., 1.0i}, {15. + 2.0i, 0. + 3.0i}};
        cout<<m1.Print();



}