//
// Created by kamila on 30.04.18.
//

#include <iostream>
#include <regex>

int main(){

    //problem to new line bo string od razu cyta \n jako newline i trzeba zmusic aby w regexie go przeczytal
   // std::regex whole_pattern(R"(((\d)\n(\d{2}):(\d{2}):(\d{2}),(\d{3}) --> (\d{2}):(\d{2}):(\d{2}),(\d{3})\n(.*)\n\n)+)");

   // std::regex line_pattern(R"((\d)\n(\d{2}):(\d{2}):(\d{2}),(\d{3}) --> (\d{2}):(\d{2}):(\d{2}),(\d{3})\n(.*)\n\n?)");

    std::regex whole_pattern(R"(((\d)\n(\d{2}):(\d{2}):(\d{2}),(\d{3}) --> (\d{2}):(\d{2}):(\d{2}),(\d{3})\n(.*(\n.*)?)\n(\n|$))+)");

    std::regex line_pattern  (R"(((\d)\n(\d{2}):(\d{2}):(\d{2}),(\d{3}) --> (\d{2}):(\d{2}):(\d{2}),(\d{3})\n(.*(\n.*)?)\n(\n|$)))");

    // LINE\nHH:MM:SS,mmm --> HH:MM:SS,mmm\nTEXT\n\n
    //   1   2  3   4  5      6  7  8  9     10

    if (std::regex_match ("1\n00:20:42,650 --> 00:20:46,609\n- How did he do that?\n- Made him an offer he couldn't refuse.\n\n", whole_pattern ))
        std::cout << "ORIGIN matched\n";

    if (std::regex_match ("1\n00:05:54,555 --> 00:05:56,722\nText\n\n", line_pattern ))
        std::cout << "sub matched\n";


    return 0;
}