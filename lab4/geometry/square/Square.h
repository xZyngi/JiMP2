//
// Created by kamila on 23.03.18.
//

#ifndef JIMP_EXERCISES_SQUARE_H
#define JIMP_EXERCISES_SQUARE_H

#include <math.h>
class Square {
private:
    std::pair<int, int> A;
    std::pair<int, int> B;
    std::pair<int, int> C;
    std::pair<int, int> D;
    double SetLength (){
        std::pair<int, int> vec = Vector(A,B);
        double length = (vec.first*vec.first) + (vec.second*vec.second);
        length = sqrt(x);
        return length;
    }


public:
    Square();
    Square(std::pair<int, int>, std::pair<int, int>,std::pair<int, int>,std::pair<int, int>);
    std::pair<int, int> Vector (std::pair<int, int>,  std::pair<int, int>);
    double Circumference(){return SetLength()*4};
    double Area (){};



};

Square::Square(){
    A = {0,0};
    B = {1,0};
    C = {1,1};
    D = {0,1};
}
Square::Square(std::pair<int, int> a,std::pair<int, int> b,std::pair<int, int> c,std::pair<int, int> d){
    A= a;
    B=b;
    C=c;
    D=d;
}

std::pair<int, int> Square::Vector(std::pair<int, int> a, std::pair<int, int> b) {
    std::pair<int, int> vec;
    vec_ba.first = b.first - a.first;
    vec_ba.second = b.second - a.second;
    return vec;
}




double Circumference (double length){
    return 4*length;
}
double Area (double length){
    return length*length;
}


#endif //JIMP_EXERCISES_SQUARE_H
