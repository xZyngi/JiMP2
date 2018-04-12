//
// Created by zyngjaku on 06.04.18.
//

#include "Matrix.h"

Matrix::Matrix() {

}

Matrix::Matrix(int number_of_col, int number_of_row) {

}

Matrix::Matrix(const std::string &str) {

}

Matrix::Matrix(const std::initializer_list<std::vector<std::complex<double>>> &elements) {

}

Matrix::Matrix(const Matrix &matrix) {

}

Matrix &Matrix::operator=(const Matrix &matrix) {

}

std::pair<size_t, size_t> Matrix::size() const {
    return pair<size_t, size_t>();
}

std::string Matrix::print() const {
    return std::__cxx11::string();
}

std::complex<double> Matrix::pop(int cols, int rows) const {
    return complex<double>();
}

void Matrix::Set(int cols, int rows, std::complex<double> val) {

}

Matrix Matrix::add(const Matrix &mat2) const {
    return Matrix();
}

Matrix Matrix::sub(const Matrix &mat2) {
    return Matrix();
}

Matrix Matrix::mul(Matrix mat2) {
    return Matrix();
}

Matrix Matrix::mul(int x) {
    return Matrix();
}

Matrix Matrix::div(Matrix mat2) {
    return Matrix();
}

Matrix Matrix::div(int x) {
    return Matrix();
}

Matrix Matrix::pow(int x) {
    return Matrix();
}
