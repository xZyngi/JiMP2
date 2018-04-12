//
// Created by zyngjaku on 06.04.18.
//

#ifndef JIMP_EXERCISES_MATRIX_H
#define JIMP_EXERCISES_MATRIX_H

#include <iostream>
#include <vector>
#include <complex>

using namespace std;

class Matrix {
public:
    Matrix();
    Matrix (int number_of_col, int number_of_row);

    Matrix (const std::string &str);
    Matrix (const std::initializer_list<std::vector<std::complex<double>>> &elements);

    Matrix(const Matrix &matrix);
    Matrix &operator=(const Matrix &matrix);

    std::pair<size_t , size_t > size() const;
    std::string print() const;
    std::complex<double> pop(int cols, int rows) const;

    void Set(int cols, int rows, std::complex<double> val);

    Matrix add(const Matrix &mat2) const;
    Matrix sub(const Matrix &mat2);
    Matrix mul(Matrix mat2);
    Matrix mul(int x);
    Matrix div( Matrix mat2);
    Matrix div(int x);
    Matrix pow(int x);

private:
    complex<double> matrix; //TODO: Make 2D dynamic array

    int number_of_row_;
    int number_od_col_;
};


#endif //JIMP_EXERCISES_MATRIX_H
