//
// Created by zyngi on 13.03.18.
//

#include <iostream>
#include <vector>
#include <sstream>
#include <regex>
#include <cmath>
#include "MinimalTimeDifference.h"

using namespace std;

int main(){

    vector <string> dane {"9:13", "17:23", "18:55", "17:34"};
    cout << minimaltimedifference::MinimalTimeDifference(dane) << endl;

    return 0;
}