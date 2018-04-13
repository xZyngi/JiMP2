//
// Created by zyngi on 21.03.18.
//

#ifndef JIMP_EXERCISES_TINYURL_H
#define JIMP_EXERCISES_TINYURL_H

#include <string>
#include <memory>
#include <array>
#include <vector>

namespace tinyurl{
    struct TinyUrlCodec{
        std::vector<std::string> url;
        std::vector<std::string> hash;
        std::array<char, 6> state;// = {'0','0','0','0','0','0'}; //tak chyba nie mozna
    };

    std::unique_ptr<TinyUrlCodec> Init();
    void NextHash(std::array<char, 6> *state);
    std::string Encode(const std::string &url, std::unique_ptr<TinyUrlCodec> *codec);
    std::string Decode(const std::unique_ptr<TinyUrlCodec> &codec, const std::string &hash);
}

#endif //JIMP_EXERCISES_TINYURL_H
