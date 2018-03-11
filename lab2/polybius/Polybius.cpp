//
// Created by zyngi on 08.03.18.
//

#include "Polybius.h"

std::string PolybiusCrypt(std::string message){

    int first_el=0, second_el=0, asci_id;
    string crypted = "", tmp;

    for(int i=0; i<message.length(); i++){
        if(message[i] > 64 && message[i] < 91) message[i] = (char)(((int)message[i]) + 32);
        if(message[i] != ' ') {
            if ((int) message[i] - 97 > 8)
                asci_id = (int) message[i] - 98;
            else
                asci_id = (int) message[i] - 97;

            first_el = (asci_id / 5) + 1;

            second_el = (asci_id + 1) % 5;
            second_el = (second_el == 0) ? 5 : (asci_id + 1) % 5;

            tmp = to_string(first_el);
            crypted+=tmp;
            tmp = to_string(second_el);
            crypted+=tmp;
        }
    }

    return crypted;
}

std::string PolybiusDecrypt(std::string crypted){

    char codes[5][5];
    int count = 0;
    string alphabet = "abcdefghiklmnopqrstuvwxyz";
    string encrypted = "";

    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            codes[i][j] = (char)alphabet[count];
            count++;
        }
    }

    cout << endl;
    for(int i=0; i<crypted.length(); i+=2){
        encrypted += codes[((int)crypted[i])-49][((int)crypted[i+1])-49];
    }

    return encrypted;
}