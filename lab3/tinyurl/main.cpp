//
// Created by zyngi on 21.03.18.
//

#include "TinyUrl.h"
#include <iostream>

int main () {
    std::array<char, 6> state= {'0','0','0','0','0','0'};
    std::array<char, 6> *pstate = &state;
    std::string hash;
    for(int i=0; i<6;i++){
        hash += state[i];
    }
    std::cout<<hash<<std::endl<<std::endl;
    std::unique_ptr<tinyurl::TinyUrlCodec> codec = tinyurl::Init();

    tinyurl::NextHash(&codec->state);
    tinyurl::NextHash(&codec->state);
    tinyurl::NextHash(&codec->state);
    for(int i=0; i<6;i++){
        std::cout<<codec->state[i]<<std::endl;
    }
    return 0;

}