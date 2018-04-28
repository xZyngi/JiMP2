//
// Created by kamila on 19.04.18.
//

#include "Iterable.h"
#include <iostream>

int main (){

    using ::utility::Zipper;
    using ::utility::ZipperIterator;
    using ::utility::IterableIterator;
    using ::std::vector;
    using ::std::string;
    using ::std::make_unique;

    vector<int> vi {4, 77, -91};
    vector<string> vs {"4", "9991", "adfskld"};
    auto it = ZipperIterator(vi.begin(),vs.begin(), vi.end(), vs.end());
    it.Next();
    std::cout<< it.Dereference().first;


}