//
// Created by edutilos on 20.09.17.
//

#include "ComplexNumber.h"

ComplexNumber::ComplexNumber() {
    this->re = 0.0;
    this->im = 0.0;
}

ComplexNumber::ComplexNumber(double re, double im) {
    this->re = re ;
    this->im = im ;
}

ComplexNumber ComplexNumber::operator+(ComplexNumber other) {
    ComplexNumber res;
    res.re = this->re + other.re ;
    res.im = this->im + other.im;
    return res;
}

ComplexNumber ComplexNumber::operator-(ComplexNumber other) {
    ComplexNumber res;
    res.re = this->re - other.re ;
    res.im = this->im - other.im;
    return res ;
}

ComplexNumber ComplexNumber::operator*(ComplexNumber other) {
    ComplexNumber res ;
    res.re = this->re*other.re - this->im*other.im;
    res.im = this->re*other.im + this->im*other.re ;
    return res;
}

ComplexNumber ComplexNumber::operator/(ComplexNumber other) {
    double factor = pow(other.re, 2) + pow(other.im, 2);
    ComplexNumber temp(other.re, -other.im);
    ComplexNumber res = this->operator*(temp);
    res = res/factor ;
    return res ;
}


ComplexNumber ComplexNumber::operator*(double factor) {
    ComplexNumber res ;
    res.re = this->re* factor;
    res.im = this->im * factor;
    return res;
}
ComplexNumber ComplexNumber::operator/(double factor) {
    ComplexNumber res;
    res.re = this->re/factor;
    res.im = this->im/factor;
    return res;
}



double ComplexNumber::getRe() const {
    return re;
}

void ComplexNumber::setRe(double re) {
    this->re = re;
}

double ComplexNumber::getIm() const {
    return im;
}

void ComplexNumber::setIm(double im) {
    this->im = im;
}


string ComplexNumber::toString() {
    stringstream ss ;
    ss << this->re <<" + i*(" << this->im << ")";
    return ss.str();
}
