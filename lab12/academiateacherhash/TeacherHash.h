//
// Created by kamila on 30.05.18.
//

#ifndef JIMP_EXERCISES_TEACHERHASH_H
#define JIMP_EXERCISES_TEACHERHASH_H

#include <string>
#include <utility>

using namespace std;

namespace academia {
    class TeacherId {
    public:
        TeacherId(int id);
        operator int() const;
        bool operator!=(const TeacherId& other) const;
    private:
        int id_;
    };

    class Teacher {
    public:
        Teacher(TeacherId id, string name, string depart);
        TeacherId Id() const;
        string Name() const;
        string Department() const;
        bool operator!=(const Teacher& other)const;
        bool operator==(const Teacher& other)const;
    private:
        TeacherId id_;
        string name_;
        string depart_;
    };

    class TeacherHash {
    public:
        TeacherHash()= default;
        size_t operator()(Teacher teacher) const;
    };
}

#endif //JIMP_EXERCISES_TEACHERHASH_H
