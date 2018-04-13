//
// Created by zyngjaku on 06.04.18.
//

#include <experimental/string_view>
#include "TextPool.h"

namespace pool {
    TextPool::TextPool() {

    }

    TextPool::TextPool(std::initializer_list<std::experimental::string_view> pool) {
        for(std::experimental::string_view v : pool) {
            this->pool.emplace(v);
        }
    }

    TextPool::TextPool(TextPool && other) {
        pool = other.pool;
        other.pool.clear();
    }

    TextPool & TextPool::operator=(TextPool && other) {
        if(this == &other)
            return *this;

        pool = other.pool;
        other.pool.clear();
    }

    TextPool::~TextPool() {

    }

    std::experimental::string_view TextPool::Intern(const std::string &str) {
        for(std::experimental::string_view v : pool){
            if(v == str)
                return *pool.emplace(str).first;
        }

        pool.insert(str);
        
        return *pool.emplace(str).first;
    }

    size_t TextPool::StoredStringCount() const {
        return pool.size();
    }
}
