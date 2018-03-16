//
// Created by zyngi on 13.03.18.
//

#include "MinimalTimeDifference.h"

namespace minimaltimedifference {
    unsigned int ToMinutes(std::string time_HH_MM) {

        string time_HH_string, time_MM_string;
        int time_HH, time_MM;
        unsigned int result_minutes;

        if (time_HH_MM[2] == ':') {
            time_HH_string = time_HH_MM.substr(0, 2);
            time_MM_string = time_HH_MM.substr(3, 5);
        } else {
            time_HH_string = time_HH_MM.substr(0, 1);
            time_MM_string = time_HH_MM.substr(2, 4);
        }

        istringstream string_to_int_HH(time_HH_string);
        string_to_int_HH >> time_HH;

        istringstream string_to_int_MM(time_MM_string);
        string_to_int_MM >> time_MM;

        result_minutes = time_HH * 60 + time_MM;

        if (result_minutes == 0) result_minutes = 1440;

        return result_minutes;
    }

    unsigned int MinimalTimeDifference(std::vector<std::string> times) {

        unsigned int minimal_time_difference = 1440, first_time, second_time, difference_between_hours, tmp;


        for (int i = 0; i < times.size(); i++) {
            for (int j = i + 1; j < times.size(); j++) {

                first_time = ToMinutes(times[i]);
                second_time = ToMinutes(times[j]);

                if(first_time > second_time) {
                    tmp = first_time;
                    first_time = second_time;
                    second_time = tmp;
                }

                difference_between_hours = second_time - first_time;
                
                if (minimal_time_difference > difference_between_hours)
                    minimal_time_difference = difference_between_hours;

                difference_between_hours = (1440-second_time) + first_time;

                if (minimal_time_difference > difference_between_hours)
                    minimal_time_difference = difference_between_hours;

            }
        }

        return minimal_time_difference;
    }
}