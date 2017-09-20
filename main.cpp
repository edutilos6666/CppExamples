#include <iostream>
#include "Person.h"

#include <iostream>
#include <string>
#include <sstream>


#include "PersonDAO.h"
#include "ComplexNumber.h"
#include "Box.h"
#include "OperatorsExample.h"

using namespace std;

void testPerson();
void testPersonDAO();
void testComplexNumber();
void testBox();
void testOperatorsExample();

int main() {
    testOperatorsExample();
    return 0;
}

void testOperatorsExample() {
    OperatorsExample ops;
    ops.arithmeticOps();
    ops.relationalOps();
    ops.logicalOps();
}

void testBox() {
    Box b1(3,3,3) , b2(2, 2, 2);
    Box bAdd = b1 + b2 ;
    Box bSubtract = b1 - b2 ;
    Box bMultiply = b1 * b2 ;
    Box bDivide = b1 / b2 ;
    Box bMultiplyBy2 = b1 * 2 ;
    Box bDivideBy2 = b1 / 2;
    bool eq = b1 == b2 ;
    bool ne = b1 != b2 ;
    bool lt = b1 < b2 ;
    bool le = b1 <= b2 ;
    bool gt = b1 > b2 ;
    bool ge = b1 >= b2 ;

    cout << "b1 = " << b1.toString() << endl;
    cout << "b2 = " << b2.toString() << endl;
    cout << "b1 + b2 = " << bAdd.toString() << endl;
    cout << "b1 - b2 = " << bSubtract.toString() << endl;
    cout << "b1 * b2 = " << bMultiply.toString() << endl;
    cout << "b1 / b2 = " << bDivide.toString() << endl;
    cout << "b1 * 2 = " << bMultiplyBy2.toString() << endl;
    cout << "b1 / 2 = " << bDivideBy2.toString() << endl;
    cout << "b1 == b2 = " << eq << endl;
    cout << "b1 != b2 = " << ne << endl;
    cout << "b1 < b2 = " << lt << endl;
    cout << "b1 <= b2 = " << le << endl;
    cout << "b1 > b2 = " << gt << endl;
    cout << "b1 >= b2 = " << ge << endl << endl;

}


void testComplexNumber() {
    ComplexNumber cn1(3,3), cn2(2,2);
    ComplexNumber cnAdd = cn1 + cn2 ;
    ComplexNumber cnSubtract = cn1 - cn2;
    ComplexNumber cnMultiply = cn1 * cn2 ;
    ComplexNumber cnDivide = cn1/ cn2 ;
    ComplexNumber cnMultiplyBy2 = cn1*2 ;
    ComplexNumber cnDivideBy2 = cn1/2 ;
    cout << "cn1 = " << cn1.toString() << endl;
    cout << "cn2 = " << cn2.toString() << endl;
    cout << "cn1 + cn2  = " << cnAdd.toString() << endl;
    cout << "cn1 - cn2 = " << cnSubtract.toString() << endl;
    cout << "cn1 * cn2 = " << cnMultiply.toString() << endl;
    cout << "cn1 / cn2 = " << cnDivide.toString() << endl;
    cout << "cn1 * 2 = " << cnMultiplyBy2.toString() << endl;
    cout << "cn1 / 2 = " << cnDivideBy2.toString() << endl;
    cout << endl;
}


void testPersonDAO() {
    PersonDAO dao;
    dao.save(Person(1, "foo", 10, 100.0, true));
    dao.save(Person(2, "bar", 20, 200.0, false));
    dao.save(Person(3, "bim", 30, 300.0, true));

    auto all = dao.findAll();
    cout << "<<all people>>" << endl ;
    for(auto p: all) {
        cout << p.toString() << endl;
    }

    cout << endl;
    //update
    dao.update(1, Person(1, "new_foo", 66, 666.6, false));

    auto one = dao.findById(1L);
    cout << "after update = " << one.toString() << endl;

    // remove
    dao.remove(1);
    all = dao.findAll();
    cout << "<<all people after remove>>" << endl;
    for (auto p: all) {
        cout << p.toString() << endl;
    }

    cout << endl;
}

void testPerson() {
    Person p1, p2;
    p1 = Person(1, "foo", 10, 100.0, true);
    p2 = Person(2, "bar", 20, 200.0, false);
    Person p3(3, "bim", 30, 300.0, true);
    cout << "p1 = " << p1.toString() << endl;
    cout << "p2 = " << p2.toString() << endl ;
    cout << "p3 = " << p3.toString() << endl;
}