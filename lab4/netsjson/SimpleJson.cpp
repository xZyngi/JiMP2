//
// Created by kamila on 23.03.18.
//

#include "SimpleJson.h"

namespace nets {
    nets::JsonValue::JsonValue(map<string, nets::JsonValue> value) {
        m_json = value;
    }

    nets::JsonValue::JsonValue(int value) {
        i_json = value;
    }

    nets::JsonValue::JsonValue(double value) {
        d_json = value;
    }

    nets::JsonValue::JsonValue(bool value) {
        b_json = value;
    }

    nets::JsonValue::JsonValue(string value) {
        s_json = value;
    }

    nets::JsonValue::JsonValue(vector<nets::JsonValue> value) {
        v_json = value;
    }

    nets::JsonValue::~JsonValue() {

    }

    nets::JsonValue nets::JsonValue::ValueByName(const string &name) const {
        for (auto n : m_json) {
            if (n.first == name) {
                return n.second;
            }
        }
    }

    string nets::JsonValue::ToString() const {
        return std::__cxx11::string();
    }
}