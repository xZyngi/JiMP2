//
// Created by kamila on 30.04.18.
//

#include <string>
#include <regex>
#include "MovieSubtitles.h"


void moviesubs::MicroDvdSubtitles::ShiftAllSubtitlesBy(int mili, int framerate, std::stringstream *in,
                                                                    std::stringstream *out) {

    std::regex whole_pattern(R"((\{(\d+)\}\{(\d+)\}.*\n?)+)");
    std::regex line_pattern(R"((\{(\d+)\}\{(\d+)\}(.*))\n?)");
    //set shift
    int rate_shift = mili / (1000 / framerate);



    std::string s= in->str();
    std::string output;
    std::smatch matched;
    int line =1;
    //not match
    if (!std::regex_match(s, whole_pattern)){
        throw InvalidSubtitleLineFormat("InvalidSubtitleLineFormat",line);
    }
        //match

    else{
        while (std::regex_search (s,matched,line_pattern)) {
            //to int
            std::string x= matched.str(1);
            int start_time=std::stoi( matched.str(2));
            int stop_time=std::stoi( matched.str(3));
            //set line

            // (2)<(1)?
            if(stop_time<start_time){
               throw SubtitleEndBeforeStart(matched.str(1),line);//  (matched(0),line)
            }

            //make shift
            start_time+=rate_shift;
            stop_time+=rate_shift;

            //are negative??
            if(start_time<0||stop_time<0){
                throw NegativeFrameAfterShift(line);
            }
            else{//replace

                //int to string
                output+= "{"+std::to_string(start_time)+"}"+"{"+std::to_string(stop_time)+"}"+ matched.str(4)+"\n";
                //output += std::regex_replace (matched.str(0),std::regex(matched.str(1)),std::to_string(start_time));


            }
            s = matched.suffix().str();
            line++;
        }

    }



    //to stringstream
    (*out)<<output;



}

void moviesubs::SubRipSubtitles::ShiftAllSubtitlesBy(int mili, int framerate, std::stringstream *in,
                                                     std::stringstream *out) {

    std::regex whole_pattern(R"(((\d)\n(\d{2}):(\d{2}):(\d{2}),(\d{3}) --> (\d{2}):(\d{2}):(\d{2}),(\d{3})\n(.*(\n.*)?)\n(\n|$))+)");

    std::regex line_pattern  (R"((\d)\n(\d{2}):(\d{2}):(\d{2}),(\d{3}) --> (\d{2}):(\d{2}):(\d{2}),(\d{3})\n(.*(\n.*)?)\n(\n|$))");

    // LINE\nHH:MM:SS,mmm --> HH:MM:SS,mmm\nTEXT\n\n
    //   1   2  3   4  5      6  7  8  9     10


    //set shift
    int rate_shift = mili;



    std::string s= in->str();
    std::string output;
    std::smatch matched;
    int line =1;
    //not match
    if (!std::regex_match(s, whole_pattern)){
        //check valid patterns
        throw InvalidSubtitleLineFormat("InvalidSubtitleLineFormat",line);
    }
        //match

    else{
        while (std::regex_search (s,matched,line_pattern)) {
            //check line number
            if(std::stoi(matched[1])!=line){
                throw OutOfOrderFrames(line);
            }

            //to int

            int start_time=std::stoi(matched[2])*60*60*1000+ std::stoi(matched[3])*60*1000 + std::stoi(matched[4])*1000 + std::stoi(matched[5]);
            int stop_time= std::stoi(matched[6])*60*60*1000+ std::stoi(matched[7])*60*1000 + std::stoi(matched[8])*1000 + std::stoi(matched[9]);


            // (2)<(1)?
            if(stop_time<start_time){
                throw SubtitleEndBeforeStart(matched.str(2)+":"+matched.str(3)+":"+matched.str(4)+","+matched.str(5)+" --> "+matched.str(6)+":"+matched.str(7)+":"+matched.str(8)+","+matched.str(9),line);
            }

            //make shift
            start_time+=rate_shift;
            stop_time+=rate_shift;

            //are negative??
            if(start_time<0||stop_time<0){
                throw NegativeFrameAfterShift(line);
            }
            else{//replace


                // LINE\n

                //int to string
                std::string start_time_str = FormatMiliSec(start_time);
                std::string stop_time_str = FormatMiliSec(stop_time);


                // LINE\nHH:MM:SS,mmm --> HH:MM:SS,mmm\nTEXT\n\n
                output+= matched.str(1)+"\n"+start_time_str+" --> "+stop_time_str;
                output+="\n"+matched.str(10)+"\n\n";



            }
            s = matched.suffix().str();
            line++;
        }

    }



    //to stringstream
    (*out)<<output;





}

std::string moviesubs::SubRipSubtitles::FormatMiliSec(int milisec) {
    int hours = milisec/(60*60*1000);
    milisec -= hours*60*60*1000;
    int minutes = milisec/(60*1000);
    milisec -= minutes*60*1000;
    int seconds = milisec/(1000);
    milisec -= seconds*1000;

    std::string formated;
    if(hours<10){
        formated+="0"+std::to_string(hours)+":";
    }
    else{
        formated+=std::to_string(hours)+":";
    }


    if(minutes<10){
        formated+="0"+std::to_string(minutes)+":";
    }
    else{
        formated+=std::to_string(minutes)+":";
    }


    if(seconds<10){
        formated+="0"+std::to_string(seconds)+",";
    }
    else{
        formated+=std::to_string(seconds)+",";
    }

    if(milisec<100) {
        formated += "0";
        if (milisec < 10) {
            formated += "0" + std::to_string(milisec);
        } else {
            formated += std::to_string(milisec);
        }
    }
    else{
        formated+=std::to_string(milisec);
    }



    return formated;
}
