//
// Created by zyngi on 08.03.18.
//

#include <iostream>
#include <fstream>
#include "Polybius.h"

using namespace std;

int main(){

    int task;
    string input_file, output_file, result;

    cin >> input_file;
    cin >> output_file;
    cin >> task;

    ifstream my_file(input_file);
    string file_content;

    if(!my_file) {
        return 0;
    }

    while(my_file >> file_content){
        //READING FILE
    }


    if(task == 1) {
        result = PolybiusCrypt("message");

    }
    else if(task == 0) {
        result = PolybiusDecrypt("32154343112215");
    }
    else{
        return 0;
    }

    cout << result << endl;


    std::ofstream out(output_file);
    out << result;
    out.close();

    return 0;
}