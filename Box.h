//
// Created by edutilos on 20.09.17.
//

#ifndef CPPEXAMPLES_BOX_H
#define CPPEXAMPLES_BOX_H

#include <iostream>
#include <sstream>
#include <string>

using namespace std;


class Box {
private:
    double width;
    double height;
    double depth;

public:
    Box();
    Box(double width , double height, double depth);

    //getter and setters
    double getWidth() const;
    void setWidth(double width);
    double getHeight() const;
    void setHeight(double height);
    double getDepth() const;
    void setDepth(double depth);
    //volume
    double volume() const;
    //operator overloading
    Box operator+(const Box other);
    Box operator-(const Box other);
    Box operator*(const Box other);
    Box operator/(const Box other);
    Box operator*(double factor);
    Box operator/(double factor);

    bool operator==(const Box other);
    bool operator!=(const Box other);
    bool operator<(const Box other);
    bool operator>(const Box other);
    bool operator<=(const Box other);
    bool operator>=(const Box other);

    //toString
    string toString();
};


#endif //CPPEXAMPLES_BOX_H
