//
// Created by zyngi on 06.03.18.
//

#include <iostream>
#include <string>
#include "Palindrome.h"

using namespace std;

int main(){

    int action;

    cout << "0. wyjdz" << endl;
    cout << "1. sprawdz palindrom" << endl;

    cin >> action;

    if(action == 1) {
        string word_to_check = "";
        cin >> word_to_check;

        cout << IsPalindrome(word_to_check) << endl;
    }

    return 0;
}