//
// Created by kamila on 26.05.18.
//

#ifndef JIMP_EXERCISES_TIMERECORDER_H
#define JIMP_EXERCISES_TIMERECORDER_H

#include <iostream>
#include <chrono>
namespace profiling {
    template<class T>
    auto TimeRecorder ( T function ){


        std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();

        auto new_record = function();

        std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();

        double duration = std::chrono::duration<double, std::milli>( t2 - t1 ).count();


        return std::make_pair(new_record, duration);
    };


}


#endif //JIMP_EXERCISES_TIMERECORDER_H
