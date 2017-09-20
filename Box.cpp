//
// Created by edutilos on 20.09.17.
//

#include "Box.h"

double Box::getWidth() const {
    return width;
}

void Box::setWidth(double width) {
    Box::width = width;
}

double Box::getHeight() const {
    return height;
}

void Box::setHeight(double height) {
    Box::height = height;
}

double Box::getDepth() const {
    return depth;
}

void Box::setDepth(double depth) {
    Box::depth = depth;
}

Box::Box() {

}

Box::Box(double width, double height, double depth) {
    this->width = width;
    this->height = height;
    this->depth = depth;
}

double Box::volume() const {
    return this->width*this->height*this->depth;
}

Box Box::operator+(const Box other) {
    Box ret;
    ret.width = this->width + other.width;
    ret.height = this->height + other.height;
    ret.depth = this->depth + other.depth ;
    return ret ;
}

Box Box::operator-(const Box other) {
    Box ret;
    ret.width = this->width - other.width ;
    ret.height = this->height - other.height;
    ret.depth = this->depth - other.depth;
    return ret ;
}

Box Box::operator*(const Box other) {
    Box ret ;
    ret.width = this->width*other.width ;
    ret.height = this->height * other.height;
    ret.depth = this->depth * other.depth;
    return ret;
}

Box Box::operator/(const Box other) {
    Box ret;
    ret.width = this->width/other.width;
    ret.height = this->height/other.height;
    ret.depth = this->depth/other.depth;
    return ret;
}

Box Box::operator*(double factor) {
    Box ret;
    ret.width = this->width*factor;
    ret.height = this->height*factor;
    ret.depth = this->depth*factor;
    return ret;
}

Box Box::operator/(double factor) {
    Box ret;
    ret.width = this->width/factor;
    ret.height = this->height/factor;
    ret.depth = this->depth/factor;
    return ret ;
}

bool Box::operator==(const Box other) {
    double v1 = this->volume();
    double v2 = other.volume();
    return v1 == v2 ;
}

bool Box::operator!=(const Box other) {
    double v1 = this->volume();
    double v2 = other.volume();
    return v1 != v2 ;
}

bool Box::operator<(const Box other) {
    double v1 = this->volume();
    double v2 = other.volume();
    return v1 < v2;
}

bool Box::operator>(const Box other) {
    double v1 = this->volume();
    double v2 = other.volume();
    return v1 > v2 ;
}

bool Box::operator<=(const Box other) {
    double v1 = this->volume();
    double v2 = other.volume();
    return v1 <= v2 ;
}

bool Box::operator>=(const Box other) {
    double v1 = this->volume();
    double v2 = other.volume();
    return v1 >= v2 ;
}

string Box::toString() {
    stringstream ss;
    ss << "Box(" << this->width << ", " << this->height << ", " << this->depth << ")";
    return ss.str();
}
