//
// Created by zyngi on 06.03.18.
//

#include <iostream>
#include "MultiplicationTable.h"

using namespace std;

void printMultiplicationTable(int tab[][10]) {

    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){

            cout << tab[i][j] << " ";

        }

        cout << endl;
    }

}

int main(){

    int tab[10][10];

    MultiplicationTable(tab);
    printMultiplicationTable(tab);

    return 0;
}