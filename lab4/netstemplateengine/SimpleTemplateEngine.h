//
// Created by kamila on 23.03.18.
//

#ifndef JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
#define JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

namespace nets {
    class View {
    public:
        View();

        View(std::string text);

        ~View();

        string Render(const std::unordered_map<std::string, std::string> &model) const;

        string GetText() const;

        void SetText(std::string text);

    private:
        string text;
    };
}

#endif //JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
