//
// Created by edutilos on 20.09.17.
//

#ifndef CPPEXAMPLES_COMPLEXNUMBER_H
#define CPPEXAMPLES_COMPLEXNUMBER_H

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std ;

class ComplexNumber {
private:
    double re;
    double im;

public:
    ComplexNumber();
    ComplexNumber(double re, double im);
    ComplexNumber operator+(ComplexNumber other);
    ComplexNumber operator-(ComplexNumber other);
    ComplexNumber operator*(ComplexNumber other);
    ComplexNumber operator/(ComplexNumber other);
    ComplexNumber operator*(double factor);
    ComplexNumber operator/(double factor);
    //getter setter
    double getRe() const;
    void setRe(double re);
    double getIm() const;
    void setIm(double im);

    string toString();
};


#endif //CPPEXAMPLES_COMPLEXNUMBER_H
