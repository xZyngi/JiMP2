//
// Created by zyngi on 06.03.18.
//

#include "DoubleBasePalindromes.h"

uint64_t DoubleBasePalindromes(int max_vaule_exculsive){

    uint64_t suma=0;
    int tmp, not_palindrome;
    string number_in_binary_system, number_in_decimal_system;

    for(int i=0; i<max_vaule_exculsive; i++){

        number_in_decimal_system=to_string(i);
        not_palindrome = false;

        for(int j=0; j<number_in_decimal_system.length(); j++){
            if(number_in_decimal_system[j]!=number_in_decimal_system[number_in_decimal_system.length()-1-j]) {
                not_palindrome = true;
                break;
            }
        }

        if(!not_palindrome) {

            tmp = i;
            number_in_binary_system = "";

            while (tmp > 0) {
                number_in_binary_system += to_string(tmp % 2);
                tmp /= 2;

            }

            for (int j = 0; j < number_in_binary_system.length(); j++) {
                if (number_in_binary_system[j] != number_in_binary_system[number_in_binary_system.length() - 1 - j]) {
                    not_palindrome = true;
                    break;
                }
            }


            if (!not_palindrome) suma+=i;

        }

    }

    return suma;
}