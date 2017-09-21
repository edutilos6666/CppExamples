//
// Created by edutilos on 21.09.17.
//

#include "InheritanceExample.h"

CustomFile::CustomFile(string filename) {
    this->filename = filename;
}

const string &CustomFile::getFilename() const {
    return filename;
}

void CustomFile::setFilename(const string &filename) {
    CustomFile::filename = filename;
}

void CustomFile::read() {
    if(this->isReadable()) {
        cout << this->filename << " was read." << endl;
    } else {
        cout << this->filename << " is not readable." << endl;
    }
}

bool CustomFile::isReadable() {
    return this->filename.find(".read") != string::npos;
}

void CustomFile::write() {
    if(this->isWritable()) {
        cout << this->filename << " was written." << endl;
    } else {
        cout << this->filename << " is not writable." << endl;
    }
}

bool CustomFile::isWritable() {
    return this->filename.find(".write") != string::npos;
}

void CustomFile::execute() {
    if(this->isExecutable()) {
        cout << this->filename << " was executed." << endl;
    } else {
        cout << this->filename << " is not executable." << endl;
    }
}

bool CustomFile::isExecutable() {
    return this->filename.find(".exe") != string::npos;
}



string CustomFile::toString() const {
    stringstream ss ;
    ss << this->filename ;
    return ss.str();
}
