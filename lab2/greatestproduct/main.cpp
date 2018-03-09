//
// Created by zyngi on 08.03.18.
//

#include <iostream>
#include <vector>
#include "GreatestProduct.h"

using namespace std;

int main(){

    int amount_of_elements, get_element, k;

    cin >> amount_of_elements;

    std::vector<int> numbers;

    for(int i=0; i<amount_of_elements; i++) {
        cin >> get_element;
        numbers.push_back(get_element);
    }

    cin >> k;

    cout << GreatestProduct(numbers, k) << endl;

    return 0;
}