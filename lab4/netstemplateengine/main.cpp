//
// Created by kamila on 23.03.18.
//

#include <iostream>
#include <string>
#include <map>
#include "SimpleTemplateEngine.h"

using namespace std;

int main(){

    nets::View view{"Test {{test}} heh {{test}}"};
    cout << view.Render({{"test", "56Q"}}) << endl;

    return 0;
}