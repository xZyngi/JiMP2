//
// Created by zyngi on 21.03.18.
//

#include <string>
#include <memory>
#include <algorithm>
#include "TinyUrl.h"

std::unique_ptr<tinyurl::TinyUrlCodec> tinyurl::Init(){
    auto codec = std::make_unique<TinyUrlCodec>();
    for(int i=0; i<6;i++){
        codec->state[i]='0';
    }
    return codec;
}

void tinyurl::NextHash(std::array<char, 6> *state){

    int i=5;
    bool done = false;

    while (not done && i>=0){
        done =true;

        if ((*state)[i]==57){
            (*state)[i]+=8;
        }
        else if ((*state)[i]==90){
            (*state)[i]+=7;
        }

        else if ((*state)[i]==122){
            (*state)[i]=48;
            i--;
            done =false;
        }
        else{
            (*state)[i]++;
        }
    }
}

std::string tinyurl::Encode(const std::string &url, std::unique_ptr<TinyUrlCodec> *codec){
    std::string hash;
    (*codec)->url.push_back(url);
    NextHash(&((*codec)->state));
    for(int i=0; i<6;i++){
        hash += (*codec)->state[i];
    }
    (*codec)->hash.push_back(hash);
    return hash;
}

std::string tinyurl::Decode(const std::unique_ptr<TinyUrlCodec> &codec, const std::string &hash){
    auto found = std::find((codec->hash).begin(), (codec->hash).end(), hash);
    if ( found != (codec->hash).end()){
        int pos = found - (codec->hash).begin();
        return (codec->url)[pos];
    }
    else{
        return "Not Found";
    }
}