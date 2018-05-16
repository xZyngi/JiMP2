//
// Created by zyngi on 15.05.18.
//

#include <sys/socket.h>
#include <functional>
#include "Algo.h"

namespace algo {
    void CopyInto(const vector<int> &v, int n_elements, vector<int> *out) {
        copy_n(v.cbegin(), n_elements, back_inserter(*out));
    }

    bool Contains(const vector<int> &v, int element) {
        return (find(v.begin(), v.end(), element) != v.end());
    }

    void InitializeWith(int initial_value, vector<int> *v) {
        fill(v->begin(), v->end(), initial_value);
    }

    vector<int> InitializedVectorOfLength(int length, int initial_value) {
        vector<int> result;
        fill_n(back_inserter(result), length, initial_value);

        return result;
    }

    vector<string> MapToString(const vector<double> &v) {
        vector<string> result;
        transform(v.begin(), v.end(), back_inserter(result), [](double i){
            return to_string(i);
        });

        return result;
    }

    set<std::string> Keys(const map<string, int> &m) {
        set<string> x;
        transform(m.begin(), m.end(), inserter(x,x.begin()), [](auto s) { return s.first; });

        return x;
    }

    bool ContainsKey(const map<string, int> &v, const string &key) {
        return (v.find(key)!=v.end());
    }


    vector<int> Values(const map<string, int> &m) {
        vector<int> x;
        transform(m.begin(), m.end(), back_inserter(x), [](auto s) { return s.second; });

        return x;
    }

    bool ContainsValue(const map<string, int> &v, int value) {
        for(auto val : v)
            return (val.second == value);

        return false;
    }

    void SortInPlace(vector<int> *v){
        sort(v->begin(), v->end());
    }

    void SortByFirstInPlace(vector<pair<int,int>> *v) {
        sort(v->begin(), v->end());
    }

    void SortBySecondInPlace(vector<pair<int,int>> *v) {
        sort(v->begin(), v->end(), [](auto p1, auto p2){ return p1.second < p2.second; });
    }

    void SortByThirdInPlace(vector<tuple<int,int,int>> *v){
        sort(v->begin(), v->end(), [](auto p1, auto p2){ return get<2>(p1) < get<2>(p2); });
    }

    int HowManyShortStrings(const vector<string> &v, int inclusive_short_length) {
        return count_if(v.begin(), v.end(), [inclusive_short_length](auto value){ return (value.size() <= inclusive_short_length); });
    }

    string Join(const string &joiner, const vector<double> &v){
        stringstream x;
        copy(v.begin(), v.begin(), ostream_iterator<double>(x,joiner.c_str()));
        return x.str();
    }


    int Sum(const vector<int> &v){
        return  accumulate(v.begin(), v.end(), 0);
    }
    int Product(const vector<int> &v){
        return accumulate(v.begin(), v.end(), 1, multiplies<int>());
    }

    vector<string> RemoveDuplicates(const vector<string> &v){
        vector<string> x=v;

        sort(x.begin(), x.end());

        auto last=unique(x.begin(), x.end());
        x.erase(last, x.end());
        return x;
    }

    void RemoveDuplicatesInPlace(vector<string> *v){
        sort((*v).begin(), (*v).end());
        auto last=unique((*v).begin(), (*v).end());
        (*v).erase(last, (*v).end());
    }

}