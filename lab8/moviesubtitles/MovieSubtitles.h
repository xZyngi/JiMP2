//
// Created by kamila on 30.04.18.
//

#ifndef JIMP_EXERCISES_MOVIESUBTITLES_H
#define JIMP_EXERCISES_MOVIESUBTITLES_H

#include <iostream>
#include <regex>
#include <exception>
namespace moviesubs{


    class SubtitlesException: public std::invalid_argument{
    public:

        SubtitlesException (std::string subtitle, int line_numb):invalid_argument(subtitle),line_(line_numb){}
        int LineAt()const{ return line_;}

        int line_;
    };

    class NegativeFrameAfterShift: public SubtitlesException{
    public:
        explicit NegativeFrameAfterShift (int line_numb):SubtitlesException(" NegativeFrameAfterShift", line_numb){}

    };

    class SubtitleEndBeforeStart: public SubtitlesException{
    public:
        SubtitleEndBeforeStart ( std::string subtitle,int line_numb):SubtitlesException("At line "+ std::to_string(line_numb)+": " + subtitle, line_numb){}


    };

    class InvalidSubtitleLineFormat: public SubtitlesException{
    public:
        explicit InvalidSubtitleLineFormat ( std::string subtitle,int line_numb):SubtitlesException(subtitle, line_numb){}



    };

    class OutOfOrderFrames : public SubtitlesException{
    public:
        OutOfOrderFrames (int line_numb):SubtitlesException("OutOfOrderFrames", line_numb){}


    };
    class MissingTimeSpecification : public SubtitlesException{ //testy przejdą bez tego
    public:


    };




    class MovieSubtitles{
    public:
        virtual void ShiftAllSubtitlesBy (int mili, int framerate, std::stringstream *in, std::stringstream * out)=0;


    };

    class MicroDvdSubtitles: public MovieSubtitles{
    public:
        MicroDvdSubtitles()= default;

        virtual void ShiftAllSubtitlesBy (int mili, int framerate, std::stringstream *in, std::stringstream * out) override ;


    };

    class SubRipSubtitles: public MovieSubtitles{
    public:

        virtual void ShiftAllSubtitlesBy (int mili, int framerate, std::stringstream *in, std::stringstream * out) override ;
        std::string FormatMiliSec(int milisec);
    };






}


#endif //JIMP_EXERCISES_MOVIESUBTITLES_H
