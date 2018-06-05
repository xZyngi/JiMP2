//
// Created by kamila on 30.05.18.
//

#include "TeacherHash.h"

namespace academia {
    TeacherId::TeacherId(int id) { id_ = id; }

    TeacherId::operator int() const { return id_; }

    Teacher::Teacher(TeacherId id, string name, string depart) : id_(id) {
        name_ = move(name);
        depart_ = move(depart);
    }

    TeacherId Teacher::Id() const { return id_; }

    string Teacher::Name() const { return name_; }

    string Teacher::Department() const { return depart_; }

    size_t TeacherHash::operator()(Teacher teacher) const {
        hash<string> StringHash;
        hash<int> IntHash;
        return IntHash(teacher.Id()) << StringHash(teacher.Department()) + StringHash(teacher.Name());
    }

    bool TeacherId::operator!=(const TeacherId &other) const {
        return ((int)(*this)) != ((int)(other));
    }

    bool Teacher::operator!=(const Teacher &other) const {
        return ((Id() != other.Id()) || (Name() != other.Name()) || (Department() != other.Department()));
    }

    bool Teacher::operator==(const Teacher &other) const {
        return ((Id() == other.Id()) || (Name() == other.Name()) || (Department() == other.Department()));
    }
}