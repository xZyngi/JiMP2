//
// Created by kamila on 10.04.18.
//

#include <utility>
#include <complex>
#include <algorithm>
#include <complex.h>
#include "Matrix.h"

algebra::Matrix::Matrix(int rows, int cols) {
    cols_ = cols;
    rows_ = rows;

}

algebra::Matrix::Matrix() {
    cols_ = 0;
    rows_ = 0;

}

algebra::Matrix::Matrix(const std::initializer_list<std::vector<std::complex<double>>> &elements): mat_(elements) {
    // size of elements = cols_
    rows_=mat_.size();
    // size of elements[i] = rows_
    cols_=mat_[0].size();

}

std::pair<size_t, size_t > algebra::Matrix::Size() const {
    std::pair<size_t, size_t> x;
    x.first=rows_;
    x.second=cols_;
    return x;
}

//Matlab constr
algebra::Matrix::Matrix(const std::string &str) {
    //[7i2, 0i0; 0i0, 0i2; 15i2, 0i3]
    bool not_met_brace = true;

    //throw away '['
    std::string matlab= str.substr(1);
    //throw away ' '
    matlab.erase(std::remove_if(matlab.begin(), matlab.end(), ::isspace), matlab.end()); //

    //7i2,0i0;0i0,0i2;15i2,0i3]

    std::string xs;
    std::string ys;
    int x;
    int y;
    std::complex<double> num;
    std::vector<std::complex<double>> row;
    int i=0;
    while(i<matlab.size() && not_met_brace){
        //7i2,0i0;.. real
        while (matlab[i]!='i'){
            xs+=matlab[i];
            i++;
        }
        x= std::stoi( xs );
        //i2,010;...
        i++;
        //2,010;...

        while ((matlab[i]!=',')||(matlab[i]!=';')||(matlab[i]!=']')){
            ys+=matlab[i];
            i++;
        }
        y= std::stoi( ys );
        //,010;...
        num.real(x);
        num.imag(y);
        row.push_back(num);


        if(matlab[i]!=','){
            i++;
        }
        else if(matlab[i]!=';'){
            i++;
            mat_.push_back(row);
            row.clear();
        }
        else if (matlab[i]!=']'){
            i++;
            mat_.push_back(row);
            not_met_brace=false;
        }

    }


}

std::string algebra::Matrix::Print() const {
    std::complex<double> num;
    std::string x;
    std::string y;
    std::string matlab;

    matlab+= '[';

    for (int i=0; i<rows_; i++){
        for(int j=0; j<cols_;j++){
            num = Pop(i,j);
            x=std::to_string(num.real());
            x.erase ( x.find_last_not_of('0') + 1, std::string::npos );
            if(x[x.size()-1]=='.'){
                x.erase(x.size()-1);
            }
            y=std::to_string(num.imag());
            y.erase ( y.find_last_not_of('0') + 1, std::string::npos );
            if(y[y.size()-1]=='.'){
                y.erase(y.size()-1);
            }

            matlab += x;
            matlab += 'i';
            matlab += y;
            matlab += ", ";
        }
        matlab.erase(matlab.size()-2);
        matlab += "; ";
    }
    if(matlab.size()>2){
        matlab.erase(matlab.size()-2);
    }
    matlab += "]";

    return matlab;
}

std::complex<double> algebra::Matrix::Pop(int row, int col) const {
    return mat_[row][col];
}

void algebra::Matrix::Set(int row, int col, std::complex<double> val) {
    mat_[row] [col]=val;

}

algebra::Matrix::Matrix(const algebra::Matrix &matrix) {
    mat_.clear();
    rows_=matrix.Size().first;
    cols_=matrix.Size().second;


    std::vector<std::complex<double>> row;
    for (int i =0; i< matrix.Size().first;i++){

        for (int j =0; j< matrix.Size().second;j++){
            row.push_back(matrix.Pop(i,j));
        }

        this->mat_.push_back(row);
        row.clear();
    }

}

algebra::Matrix algebra::Matrix::Add(const algebra::Matrix &mat2) const {
    if (this->Size()!= mat2.Size()){
        Matrix zero;
        return zero;
    }
    else{
        Matrix result (rows_,cols_);
        std::vector<std::complex<double>> row;
        for (int i =0; i< rows_;i++){

            for (int j =0; j< cols_;j++){
                row.push_back(this->Pop(i,j) + mat2.Pop(i,j));
            }

            result.mat_.push_back(row);
            row.clear();
        }


        return result;
    }
}

algebra::Matrix algebra::Matrix::Sub(const algebra::Matrix &mat2) {
    if (this->Size()!= mat2.Size()){
        Matrix zero;
        return zero;
    }
    else{
        Matrix result (this->Size().first,this->Size().second);
        std::vector<std::complex<double>> row;
        for (int i =0; i< this->Size().first;i++){

            for (int j =0; j< this->Size().second;j++){
                row.push_back(this->Pop(i,j) - mat2.Pop(i,j));
            }

            result.mat_.push_back(row);
            row.clear();
        }


        return result;
    }
}

algebra::Matrix algebra::Matrix::Mul(algebra::Matrix mat2) {
    int this_rows = rows_;
    int this_cols = cols_;
    int mat2_rows = mat2.Size().first;
    int mat2_cols = mat2.Size().second;

    if (this_cols!=mat2_rows){
        Matrix zero;
        return zero;
    }

    else{
        std::vector<std::complex<double>> row;
        Matrix result (this_rows,mat2_cols);
        std::complex<double> num(0,0);

        for(int a=0; a<this_rows;a++){
            for(int b=0; b<mat2_cols;b++){
                for(int i=0; i<this_cols;i++){
                    num += this->Pop(a,i)*(mat2.Pop(i,b));
                }
                row.push_back(num);
                num=0+0i;
            }
            result.mat_.push_back(row);
            row.clear();
        }

        return result;

    }

}

algebra::Matrix algebra::Matrix::Pow(int x) {
    if (x == 0) {
        Matrix identity(this->Size().first, this->Size().second);
        std::vector<std::complex<double>> row;


        for (int i = 0; i < this->Size().first; i++) {

            for (int j = 0; j < this->Size().second; j++) {
                if(i==j){
                    row.push_back(1+0i);
                }
                else{
                    row.push_back(0+0i);
                }
            }
            identity.mat_.push_back(row);
            row.clear();
        }
        return identity;


    }
    else if(x==1){
        return *this;

    }
    else{
        if(rows_!=cols_){
            Matrix zero;
            return zero;
        }
        Matrix result=*this;
        for (int i =1; i<x;i++){
            result=result.Mul(*this);
        }

        return result;

    }
}

algebra::Matrix::~Matrix() {


    }





algebra::Matrix &algebra::Matrix::operator=(const algebra::Matrix &matrix) {
    if (this == &matrix) {
        return *this;
    }

    for(int i=0; i<rows_;i++){
        mat_[i].clear();
    }
    mat_.clear();


    std::vector<std::complex<double>> row;
    for (int i =0; i< matrix.Size().first;i++){

        for (int j =0; j< matrix.Size().second;j++){
            row.push_back(matrix.Pop(i,j));
        }

        mat_.push_back(row);
        row.clear();
    }
    return *this;

}


