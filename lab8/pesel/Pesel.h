//
// Created by zyngi on 30.04.18.
//

#ifndef JIMP_EXERCISES_PESEL_H
#define JIMP_EXERCISES_PESEL_H

#include <iostream>
#include <stdexcept>
#include <string.h>
#include <sstream>

using namespace std;

namespace academia {

    class AcademiaDataValidationError : public runtime_error {
    public:
        AcademiaDataValidationError(string str):runtime_error(str){

        }
    private:
    };

    class InvalidPeselChecksum : public AcademiaDataValidationError {
    public:
        InvalidPeselChecksum(string pesel, int checkSum):AcademiaDataValidationError("Invalid PESEL(" + pesel + ") checksum: "+ to_string(checkSum)){

        }
    };

    class InvalidPeselCharacter : public AcademiaDataValidationError {
    public:
        InvalidPeselCharacter(string pesel):AcademiaDataValidationError("Invalid PESEL(" + pesel + ") character set"){

        }
    };

    class InvalidPeselLength : public AcademiaDataValidationError {
    public:
        InvalidPeselLength(string pesel, int length):AcademiaDataValidationError("Invalid PESEL(" + pesel + ") length: " + to_string(length)) {

        }
    };

    class Pesel {
    public:
        Pesel();
        Pesel(string pesel);
        ~Pesel();

        void validatePESEL(string pesel);

    private:
        string pesel_;
    };
}

#endif //JIMP_EXERCISES_PESEL_H
