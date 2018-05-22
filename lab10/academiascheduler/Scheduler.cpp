//
// Created by kamila on 16.05.18.
//

#include "Scheduler.h"
#include <algorithm>
#include <set>

academia::Schedule academia::Schedule::OfTeacher(int teacher_id) const {
    Schedule scheduleofteacher;
    for(auto i:schedule_){
        if (i.TeacherId()==teacher_id){
            scheduleofteacher.InsertScheduleItem(i);
        }
    }

/*std::transform(schedule_.begin(), schedule_.end(), std::back_inserter(scheduleofteacher.schedule_), // =vecotr<SchedulingItem>
               [teacher_id](auto i){if(teacher_id==i.TeacherId()) return i;});*/
    //     ? ? ?

return scheduleofteacher;
}

academia::Schedule academia::Schedule::OfRoom(int room_id) const {
    Schedule scheduleofroom;
    for(auto i:schedule_){
        if (i.RoomId()==room_id){
            scheduleofroom.InsertScheduleItem(i);
        }
}

return scheduleofroom;
}

academia::Schedule academia::Schedule::OfYear(int year) const {
    Schedule scheduleofyear;
    for(auto i:schedule_){
        if (i.Year()==year){
            scheduleofyear.InsertScheduleItem(i);
    }
}

return scheduleofyear;
}

std::vector<int> academia::Schedule::AvailableTimeSlots(int n_time_slots) const {
    std::vector<int> takenslots;
    std::vector<int> freeslots;

    for(auto i:schedule_){
        takenslots.emplace_back(i.TimeSlot());
    }

    std::sort(takenslots.begin(),takenslots.end());
    auto last = std::unique(takenslots.begin(), takenslots.end());
    takenslots.erase(last,takenslots.end());

    int k=0;

    for (int j=1,k=0;j<=n_time_slots;j++){
        if(k<takenslots.size() && takenslots[k]==j){
            ++k;
        }
        else{
            freeslots.emplace_back(j);
        }
    }

    return freeslots;





}

void academia::Schedule::InsertScheduleItem(const academia::SchedulingItem &item) {
    schedule_.emplace_back(item);
}

size_t academia::Schedule::Size() const {
    return schedule_.size();
}

academia::SchedulingItem academia::Schedule::operator[](int number) const {
    return schedule_[number];
}

academia::Schedule academia::GreedyScheduler::PrepareNewSchedule(const std::vector<int> &rooms,
                                                                 const std::map<int, std::vector<int>> &teacher_courses_assignment,
                                                                 const std::map<int, std::set<int>> &courses_of_year,
                                                                 int n_time_slots) {
    //STUPIDEST IMPLEMENTATION EVER SEEN

    // check number of courses <= number of available slots

    //SchedulingItem:
    int _course_id;
    int _teacher_id;
    int _room_id;
    int _time_slot;
    int _year;
    bool found = false;

    Schedule new_schedule;


    // create the ntimeslots vector of free rooms and year having lessons at that time slot(index)
    std::vector< std::tuple <std::vector<int>,std::set<int>, std::set<int> > > time_room_year_teacher;


    for(int a=0;a<n_time_slots;a++){
        //std::set<int> room(rooms.begin(),rooms.end());
        std::set<int> year;
        std::set<int> teacher;

        time_room_year_teacher.emplace_back(std::make_tuple (rooms,year,teacher));
    }

    int time=0;


    for(auto i:teacher_courses_assignment){ // <id,courses>
        // [ ****teacher****]

        _teacher_id=i.first;

        //  for his course //not found
        for (auto j:i.second){
            //[ ***course**** ]
            _course_id=j;




            for (auto map_year=courses_of_year.begin();map_year!=courses_of_year.end() && not found; ++map_year) {

                if (map_year->second.find(_course_id) != map_year->second.end()) { //found in year
                    found = true;
                    //  [***year***]
                    _year = map_year->first;
                }// found in year
            }
            if(not found) {
                throw NoViableSolutionFound("course not founded in any year");
            }
            found = false;

            time=0;
            while (time<n_time_slots && not found) { // check if there is room in time slot for year

                // has the _year any lessons at that time?


                //yes
                if (std::get<1>(time_room_year_teacher[time]).find(_year) != std::get<1>(time_room_year_teacher[time]).end()) {
                    ++time;

                }
                    //no
                else {

                    // has the _teacher any lessons at that time?
                    //yes
                    if (std::get<2>(time_room_year_teacher[time]).find(_teacher_id) != std::get<2>(time_room_year_teacher[time]).end()) {
                        ++time;

                    }
                    //no
                    else{
                        // is there a free room at that time?
                        //yes
                        if (!std::get<0>(time_room_year_teacher[time]).empty()) {
                            //[ ****room**** ]
                            _room_id = std::get<0>(time_room_year_teacher[time]).back();
                            //[ ****time**** ]
                            _time_slot = time + 1;

                            std::get<0>(time_room_year_teacher[time]).pop_back();
                            std::get<1>(time_room_year_teacher[time]).insert(_year);
                            std::get<2>(time_room_year_teacher[time]).insert(_teacher_id);
                            found = true;

                        }
                            //no
                        else {
                            ++time;
                        }

                    }







                }
            }


            if(not found){
                throw NoViableSolutionFound("room or time not founded");
            }

            found= false;
            new_schedule.InsertScheduleItem(SchedulingItem(_course_id,_teacher_id, _room_id, _time_slot, _year));

        }

    }

    return new_schedule;


}




/*
std::vector<std::vector<int>> available_rooms;
for(int a=0;a<n_time_slots;a++){
available_rooms.emplace_back(rooms);
}

std::map<int, std::set<int>> year_not_avail;
for(auto m:courses_of_year){
year_not_avail.insert(std::pair<int, std::set<int>>(m.first,{}));
}


for(auto i:teacher_courses_assignment){ // <id,courses>
// [ ****teacher****]
_teacher_id=i.first;
_time_slot=1;

//  for his course //not found
for (auto j:i.second){
//[***course****]
_time_slot++;
_course_id=j;


for (auto year=courses_of_year.begin();year!=courses_of_year.end() && not found; ++year){
// nie działa bo zawsze bedzie znajdować pierwszy rok......
if(year->second.find(_course_id)!=year->second.end()){ //found in year

//  [***year***]
_year=year->first;


while (_time_slot<=n_time_slots && not found){
// sprawdź czy wtedy rok nie ma zajeć
if(year_not_avail[_year-1].find(_time_slot)==year_not_avail[_year-1].end()){ // tu to juz totalnie bezsens
//find room
if (!available_rooms[_time_slot-1].empty()){
// [ ***** room ***** ]
_room_id=available_rooms[_time_slot-1].back();
available_rooms[_time_slot-1].pop_back();
found=true;
// [ ***** time_slot ***** ]
}


}
if(not found){
_time_slot++;
}

}//przeszukał wszystkie sloty i pokoje
if(not found) { //not found place for year
throw NoViableSolutionFound("not found room for year");
}



}


}// przeszukał lata

if(not found) { //not found place for year
throw NoViableSolutionFound("not found year for course");
} else{
new_schedule.InsertScheduleItem(SchedulingItem(_course_id,_teacher_id, _room_id, _time_slot, _year));
}



}

*/
