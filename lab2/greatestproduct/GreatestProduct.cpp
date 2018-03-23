//
// Created by zyngi on 08.03.18.
//

#include "GreatestProduct.h"

int GreatestProduct(const std::vector<int> &numbers, int k){

    std::vector<int> sorted_numbers;

    int greatest_product = -9999;

    for(int i=0; i<numbers.size(); i++){
        auto position = std::upper_bound(sorted_numbers.cbegin(), sorted_numbers.cend(), numbers[i]);
        sorted_numbers.insert(position, numbers[i]);
    }

    for(int i=0; i<sorted_numbers.size(); i++){
        cout << sorted_numbers[i] << " ";
    }

    cout << endl << endl;


    std::vector<int> plus_numbers;
    std::vector<int> minus_numbers;

    for(int i=0; i<numbers.size(); i++){
        if(numbers[i] >= 0) {
            auto position = std::upper_bound(plus_numbers.cbegin(), plus_numbers.cend(), numbers[i]);
            plus_numbers.insert(position, numbers[i]);
        }
        else {
            auto position = std::upper_bound(minus_numbers.cbegin(), minus_numbers.cend(), numbers[i]);
            minus_numbers.insert(position, numbers[i]);
        }
    }

    if(plus_numbers.size() > 0) greatest_product = plus_numbers[0];
    if(minus_numbers.size() > 0) greatest_product = minus_numbers[0];

    if(k==2){
        if(plus_numbers.size() > 1){
            if(plus_numbers[plus_numbers.size()-1] * plus_numbers[plus_numbers.size()-2] > greatest_product)
                greatest_product = plus_numbers[plus_numbers.size()-1] * plus_numbers[plus_numbers.size()-2];
        }

        if(minus_numbers.size() > 1){
            if(minus_numbers[0] * minus_numbers[1] > greatest_product)
                greatest_product = minus_numbers[0] * minus_numbers[1];
        }
    }
    else if(k==3){
        if(plus_numbers.size() > 2){
            if(plus_numbers[plus_numbers.size()-1] * plus_numbers[plus_numbers.size()-2] * plus_numbers[plus_numbers.size()-3] > greatest_product)
                greatest_product = plus_numbers[plus_numbers.size()-1] * plus_numbers[plus_numbers.size()-2] * plus_numbers[plus_numbers.size()-3];
        }
        if(minus_numbers.size() > 1 && plus_numbers.size() > 0){
            if(minus_numbers[0] * minus_numbers[1] * plus_numbers[plus_numbers.size()-1] > greatest_product)
                greatest_product = minus_numbers[0] * minus_numbers[1] * plus_numbers[plus_numbers.size()-1];
        }
        if(minus_numbers.size() > 2){
            if(minus_numbers[minus_numbers.size()-1] * minus_numbers[minus_numbers.size()-2] * minus_numbers[minus_numbers.size()-3] > greatest_product)
                greatest_product = minus_numbers[minus_numbers.size()-1] * minus_numbers[minus_numbers.size()-2] * minus_numbers[minus_numbers.size()-3];
        }
    }
    else if(k==4){
        int expression;

        if(plus_numbers.size() > 1 && minus_numbers.size() > 1){
            expression = plus_numbers[plus_numbers.size()-1] * plus_numbers[plus_numbers.size()-2] * minus_numbers[0] * minus_numbers[1];
            if(expression > greatest_product)
                greatest_product = expression;
        }
        if(minus_numbers.size() > 3){
            expression = minus_numbers[0] * minus_numbers[1] * minus_numbers[2] * minus_numbers[3];
            if(expression > greatest_product)
                greatest_product = expression;
        }
        if(plus_numbers.size() > 3){
            expression = plus_numbers[plus_numbers.size()-1] * plus_numbers[plus_numbers.size()-2] * plus_numbers[plus_numbers.size()-3] * plus_numbers[plus_numbers.size()-4];
            if(expression > greatest_product)
                greatest_product = expression;
        }

    }


    return  greatest_product;
}