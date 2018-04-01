//
// Created by kamila on 23.03.18.
//

#include <algorithm>
#include <map>
#include "SimpleTemplateEngine.h"

namespace nets {
    View::View() {
        //nothing to do here
    }

    View::View(std::string text) {
        this->text = text;
    }

    View::~View() {
        //nothing to do
        //just chillin' here
    }

    std::string View::Render(const std::unordered_map<std::string, std::string> &model) const {

        string text_tmp = text;

        for(auto element = model.begin(); element != model.end(); ++element){
            string element_to_change = "{{" + element->first + "}}";
            while (text_tmp.find("{{" + element->first + "}}") != string::npos) {
                text_tmp.replace(text_tmp.find("{{" + element->first + "}}"), element->first.length() + 4, element->second);
            }
        }

        int begin=0, end=0;
        while(begin <= text_tmp.length() && end <= text_tmp.length()){
            if(text_tmp[begin] == '{' && text_tmp[begin+1] == '{'){
                //Znalazłem DWA nawiasy otwierające!

                end=begin+2;
                string word_tmp="";

                while(text_tmp[end] != '}' && end <= text_tmp.length()){
                    word_tmp += text_tmp[end];

                    end++;
                }

                if(text_tmp[end] == '}' && text_tmp[end+1] == '}') {
                    //Znalazłem WYRAZ, który nie został zastąpiony!

                    bool flag=false;

                    for(auto element = model.begin(); element != model.end(); ++element){
                        if(element->second == "{{" + word_tmp + "}}"){
                            flag=true;
                        }
                    }

                    if(begin != std::string::npos && !flag) text_tmp.erase(begin, end - begin + 2);
                }

            }

            begin++;
        }


        return text_tmp;
    }

    std::string View::GetText() const {

        return text;
    }

    void View::SetText(std::string text) {
        this->text = text;
    }
}
