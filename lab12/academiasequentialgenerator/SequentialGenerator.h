//
// Created by kamila on 04.06.18.
//

#ifndef JIMP_EXERCISES_SEQUENTIALGENERATOR_H
#define JIMP_EXERCISES_SEQUENTIALGENERATOR_H


template <class IdType, class CounterType>
//counter operator ++, operator int
class SequentialIdGenerator {
public:
    SequentialIdGenerator(CounterType counter=0): counter_(counter){}
    IdType NextValue(){

        int int_counter= int(counter_);
        IdType new_id(int_counter);
        ++counter_;

        return new_id;
    }
private:
    CounterType counter_;

};


#endif //JIMP_EXERCISES_SEQUENTIALGENERATOR_H
