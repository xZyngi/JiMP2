//
// Created by zyngi on 06.03.18.
//

#include "Palindrome.h"

bool is_palindrome(string str){

    for(int i=0; i<str.length(); i++){
        if(str[i]!=str[str.length()-1-i])
            return false;
    }

    return true;
}