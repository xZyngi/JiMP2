//
// Created by zyngjaku on 06.04.18.
//

#include <experimental/string_view>
#include "TextPool.h"

namespace pool {
    TextPool::TextPool() {

    }

    TextPool::TextPool(initializer_list<string> str) {

    }

    std::experimental::string_view TextPool::Intern(const std::string &str) {
        return nullptr;
    }

    size_t TextPool::StoredStringCount() const {
        return 0;
    }
}
