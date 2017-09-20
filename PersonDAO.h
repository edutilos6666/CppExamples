//
// Created by edutilos on 20.09.17.
//

#ifndef CPPEXAMPLES_PERSONDAOIMPL_H
#define CPPEXAMPLES_PERSONDAOIMPL_H

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "Person.h"

using namespace std ;

class PersonDAO {
private:
    map<long,Person> container;

public:
    void save(Person p);
    void update(long id, Person newP);
    void remove(long id);
    Person findById(long id);
    vector<Person> findAll();
};


#endif //CPPEXAMPLES_PERSONDAOIMPL_H
