//
// Created by edutilos on 21.09.17.
//

#ifndef CPPEXAMPLES_INHERITANCEEXAMPLE_H
#define CPPEXAMPLES_INHERITANCEEXAMPLE_H

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Readable {
public:
    virtual void read() =0;
    virtual bool isReadable() = 0 ;
};


class Writable {
public:
    virtual void write() = 0;
    virtual bool isWritable() = 0 ;
};





class Executable {
public:
    virtual void execute() = 0;
    virtual bool isExecutable() = 0;
};


class CustomFile: Readable, Writable, Executable {
private:
    string filename ;
public:
    CustomFile(string filename);
    //getter and setter
    const string &getFilename() const;
    void setFilename(const string &filename);
    //override methods
    void read() override;
    bool isReadable() override;
    void write() override;
    bool isWritable() override;
    void execute() override;
    bool isExecutable() override;
    //toString
    string toString() const;
};


#endif //CPPEXAMPLES_INHERITANCEEXAMPLE_H
