//
// Created by edutilos on 20.09.17.
//

#include "Person.h"

Person::Person() {

}

Person::Person(long id, string name, int age, double wage, bool active) {
   this->id = id ;
    this->name = name;
    this->age = age;
    this->wage = wage;
    this->active = active;
}

Person::~Person() {

}



void Person::setId(long id) {
    this->id = id;
}

void Person::setName(string name) {
    this->name = name;
}

void Person::setAge(int age) {
    this->age = age;
}

void Person::setWage(double wage) {
    this->wage = wage;
}

void Person::setActive(bool active) {
    this->active = active;
}

long Person::getId() {
    return this->id ;
}

string Person::getName() {
    return this->name ;
}

int Person::getAge() {
    return this->age ;
}

double Person::getWage() {
    return this->wage ;
}

bool Person::isActive() {
    return this->active;
}

string Person::toString() {
    stringstream ss ;
//    ss << "id = " << this->id << endl
//<< "name = " << this->name << endl
//<< "age = " << this->age << endl
//<< "wage = " << this->wage << endl
//<< "active = " << this->active << endl;
//    return ss.str();

    ss << "[" << this->id << ", " << this->name
<< ", " << this->age << ", " << this->wage
<< ", " << this-> active << "]";
    return ss.str();
}
