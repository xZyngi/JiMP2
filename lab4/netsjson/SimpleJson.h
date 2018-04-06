//
// Created by kamila on 23.03.18.
//

#ifndef JIMP_EXERCISES_SIMPLEJSON_H
#define JIMP_EXERCISES_SIMPLEJSON_H

#include <experimental/optional>
#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

namespace nets {
    class JsonValue {
    public:
        JsonValue(map<string, JsonValue> value);
        JsonValue(int value);
        JsonValue(double value);
        JsonValue(bool value);
        JsonValue(string value);
        JsonValue(vector<JsonValue> value);
        ~JsonValue();

        JsonValue ValueByName(const string &name) const;
        string ToString() const;
    private:
        map<string, JsonValue> m_json;
        experimental::optional<int> i_json;
        experimental::optional<double> d_json;
        experimental::optional<bool> b_json;
        experimental::optional<string> s_json;
        experimental::optional<vector<JsonValue>> v_json;
    };
}


#endif //JIMP_EXERCISES_SIMPLEJSON_H
