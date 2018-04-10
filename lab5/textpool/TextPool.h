//
// Created by zyngjaku on 06.04.18.
//

#ifndef JIMP_EXERCISES_TEXTPOOL_H
#define JIMP_EXERCISES_TEXTPOOL_H

#include <iostream>
#include <initializer_list>
#include <string>
#include <experimental/string_view>
#include <set>

using namespace std;

namespace pool{
    class TextPool{
    public:
        TextPool();
        TextPool(std::initializer_list<std::experimental::string_view>);

        TextPool(TextPool &&other);
        TextPool &operator=(TextPool &&other);

        ~TextPool();

        std::experimental::string_view Intern(const std::string &str);
        size_t StoredStringCount() const;
    private:
        std::set<std::experimental::string_view> pool;
    };
}

#endif //JIMP_EXERCISES_TEXTPOOL_H
