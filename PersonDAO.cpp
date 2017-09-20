//
// Created by edutilos on 20.09.17.
//

#include "PersonDAO.h"

void PersonDAO::save(Person p) {
    this->container.insert(pair<long, Person>(p.getId(), p));
}

void PersonDAO::update(long id, Person newP) {
    this->container.erase(id);
    this->container.insert(pair<long, Person>(id, newP));
}

void PersonDAO::remove(long id) {
    this->container.erase(id);
}

Person PersonDAO::findById(long id) {
    return this->container[id];
}

vector<Person> PersonDAO::findAll() {
    vector<Person> ret ;
    for(auto it = this->container.begin(); it != this->container.end(); ++it) {
        ret.push_back(it->second);
    }

    return ret ;
}
