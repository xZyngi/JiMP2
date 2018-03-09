//
// Created by zyngi on 08.03.18.
//

#include "GreatestProduct.h"

int GreatestProduct(const std::vector<int> &numbers, int k){

    int max_product = 0;

    for(int i=0; i<numbers.size(); i++){
        if(k>numbers.size()) break;

        if(numbers[i+k]/numbers[i] > max_product) max_product = numbers[i+k]/numbers[i];
    }

    return max_product;
}