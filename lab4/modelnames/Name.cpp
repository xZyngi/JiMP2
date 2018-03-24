//
// Created by kamila on 23.03.18.
//

#include "Name.h"

namespace model{
    Name::Name(const string &first_names_surname) {

        string names[] = {"", "", "", ""};
        string tmp="";
        int count, first = 0, last = 0;
        cout << first_names_surname << endl << endl;

        while (first < first_names_surname.length()) {
            tmp="";

            while (first_names_surname[last] != ' ' && last < first_names_surname.length()) {
                tmp+=first_names_surname[last];
                last++;
            }

            names[count]=tmp;
            count++;

            first = last+1;
            last++;
        }

        FirstName() = names[0];

        if(names[2] != "") SecondName() = names[1];
        else Surname() = names[1];

        if(names[3] != "") ThirdName() = names[1];
        else if(names[2] != "") Surname() = names[2];

        if(names[2] != "" && names[3] != "") ThirdName() = names[1];


    }

    string Name::FirstName() const {
        return std::__cxx11::string();
    }

    optional<string> Name::SecondName() const {
        return optional<string>();
    }

    optional<string> Name::ThirdName() const {
        return optional<string>();
    }

    string Name::Surname() const {
        return std::__cxx11::string();
    }

    string Name::ToFullInitials() const {
        return std::__cxx11::string();
    }

    string Name::ToFirstNamesInitials() const {
        return std::__cxx11::string();
    }

    string Name::ToSurnameNames() const {
        return std::__cxx11::string();
    }

    string Name::ToNamesSurname() const {
        return std::__cxx11::string();
    }

    bool Name::IsBeforeBySurname(const Name &other) const {
        return false;
    }

    bool Name::IsBeforeByFirstName(const Name &other) const {
        return false;
    }
}