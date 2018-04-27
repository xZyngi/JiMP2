//
// Created by zyngi on 26.04.18.
//

#ifndef JIMP_EXERCISES_MICRODVDSUBTITLES_H
#define JIMP_EXERCISES_MICRODVDSUBTITLES_H

#include <iostream>
#include <string>

using namespace std;

namespace moviesubs {

    class NegativeFrameAfterShift{
        //Zła klatka
    };

    class SubtitleEndBeforeStart{
        //Napis konczy sie przed wyswietleniem
    };

    class InvalidSubtitleLineFormat{
        //Zły format wpisany
    };

    class MicroDvdSubtitles {
    public:
        MicroDvdSubtitles();
        MicroDvdSubtitles(string init_sub);
        ~MicroDvdSubtitles();

        void delay(const char* in, const char* out,int delay, int fps);
    private:
        string init_sub;
    };
}

#endif //JIMP_EXERCISES_MICRODVDSUBTITLES_H
