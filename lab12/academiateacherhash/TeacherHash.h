//
// Created by kamila on 30.05.18.
//

#ifndef JIMP_EXERCISES_TEACHERHASH_H
#define JIMP_EXERCISES_TEACHERHASH_H

namespace academia{



    template <class Id>
    class TeacherId{
        //TeacherId should be castable to Int
    public:
        //constructor
        TeacherId(Id id): id_(id){}
        // (=) operator

        //(==) operator

    private:
        Id id_;
    };

    template <class Id>
    class Teacher{
    public:
        // constructor

        //id

        // name
        // department
        //  (=) operator ???

        // (==) operator



    };


    class TeacherHash {
    public:
    };
}



#endif //JIMP_EXERCISES_TEACHERHASH_H
