//
// Created by zyngi on 08.03.18.
//

#include "GreatestProduct.h"

int GreatestProduct(const std::vector<int> &numbers, int k){

    int a = numbers[0], b = numbers[1];

    for (int i=0; i<numbers.size(); i++)
        for (int j=i+1; j<numbers.size(); j++)
            if (numbers[i]*numbers[j] > a*b)
                a = numbers[i], b = numbers[j];

    return a*b;
}