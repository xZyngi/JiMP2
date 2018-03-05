//
// Created by zyngi on 05.03.18.
//

#include "ReverseString.h"

string reverse(string str){
    const char *character = str.c_str();
    size_t size = str.size();

    if (character[0] == '\0') return "";
    string reverse_string = str.substr(1,size - 1 );
    return reverse(reverse_string) + str[0];
}
