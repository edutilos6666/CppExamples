#include <iostream>
#include "Person.h"

#include <iostream>
#include <string>
#include <sstream>


#include "PersonDAO.h"
#include "ComplexNumber.h"
#include "Box.h"
#include "OperatorsExample.h"
#include "InheritanceExample.h"


#include <mysql_connection.h>
#include <mysql_driver.h>

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>


#include "MysqlConnectorExample.h"

using namespace std;

void testPerson();
void testPersonDAO();
void testComplexNumber();
void testBox();
void testOperatorsExample();
void testInheritanceExample();
void testMysql();
void testStringStream();
void testMysqlConnectorExample();
void testUserInput();
void testUserInput2();

int main() {
    testUserInput2();
    return 0;
}

void testUserInput2() {
    long id;
    string name;
    int age;
    double wage;
    bool active;

    cout << "insert your id , name , age, wage and active: " << endl;
    // whitespace separated
    cin >> id >> name >> age >> wage >> boolalpha >> active  ;
    cout << "<<Your inputs>>" << endl;
    cout << "id = " << id << endl ;
    cout << "name = " << name << endl;
    cout << "age = " << age << endl;
    cout << "wage = " << wage << endl;
    cout << "active = " << boolalpha << active  << endl;
    cout << endl;
}

void testUserInput() {
    long id;
    string name;
    int age;
    double wage;
    bool active;

    cout << "insert your id: " << endl;
    cin >> id ;
    cout << "insert your name: " << endl;
    cin >> name;
    cout << "insert your age: " << endl;
    cin >> age;
    cout << "insert your wage: " << endl;
    cin >> wage;
    cout << "insert whether you are active: " << endl;
    cin >> boolalpha >> active ;
    cout << "<<Your inputs>>" << endl;
    cout << "id = " << id << endl ;
    cout << "name = " << name << endl;
    cout << "age = " << age << endl;
    cout << "wage = " << wage << endl;
    cout << "active = " << boolalpha << active  << endl;
    cout << endl;
}


void testMysqlConnectorExample() {
   MysqlConnectorExample runner ;
    runner.example1();
}


void testStringStream() {
  stringstream ss ;
    ss << "foo" ;
    cout << ss.str() << endl;
    ss.str("");
    ss.clear();
    ss << "bar";
    cout << ss.str() << endl;
}

void testMysql() {
    cout << endl;
    cout << "Running 'SELECT 'Hello World!' AS _message'..." << endl;

    try {
        sql::Driver *driver;
        sql::Connection *con;
        sql::Statement *stmt;
        sql::ResultSet *res;

        /* Create a connection */

        driver = get_driver_instance();
//        driver = sql::mysql::get_driver_instance();    //requires #include <mysql_driver.h>
      //  con = driver->connect("tcp://127.0.0.1:3306", "root", "root");
        con = driver->connect("localhost", "root", "root");
        /* Connect to the MySQL test database */
        con->setSchema("test");

        stmt = con->createStatement();
        res = stmt->executeQuery("SELECT 'Hello World!' AS _message");
        while (res->next()) {
            cout << "\t... MySQL replies: ";
            /* Access column data by alias or column name */
            cout << res->getString("_message") << endl;
            cout << "\t... MySQL says it again: ";
            /* Access column data by numeric offset, 1 is the first column */
            cout << res->getString(1) << endl;
        }
        delete res;
        delete stmt;
        delete con;

    } catch (sql::SQLException &e) {
        cout << "# ERR: SQLException in " << __FILE__;
        cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
        cout << "# ERR: " << e.what();
        cout << " (MySQL error code: " << e.getErrorCode();
        cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }

    cout << endl;
}

void testInheritanceExample() {
    CustomFile cf1("foo.read"),
    cf2("foo.write"),
    cf3("foo.exe"),
    cf4("foo.read.write.exe");

    cout << "<<Infos on " << cf1.toString() << endl;
    cout << "is readable = " << cf1.isReadable() << endl;
    cout << "is writable = " << cf1.isWritable() << endl;
    cout << "is executable = " << cf1.isExecutable() << endl;
    cf1.read();
    cf1.write();
    cf1.execute();
    cout << endl;

    cout << "<<Infos on " << cf2.toString() << endl;
    cout << "is readable = " << cf2.isReadable() << endl;
    cout << "is writable = " << cf2.isWritable() << endl;
    cout << "is executable = " << cf2.isExecutable() << endl;
    cf2.read();
    cf2.write();
    cf2.execute();
    cout << endl;



    cout << "<<Infos on " << cf3.toString() << endl;
    cout << "is readable = " << cf3.isReadable() << endl;
    cout << "is writable = " << cf3.isWritable() << endl;
    cout << "is executable = " << cf3.isExecutable() << endl;
    cf3.read();
    cf3.write();
    cf3.execute();
    cout << endl;


    cout << "<<Infos on " << cf4.toString() << endl;
    cout << "is readable = " << cf4.isReadable() << endl;
    cout << "is writable = " << cf4.isWritable() << endl;
    cout << "is executable = " << cf4.isExecutable() << endl;
    cf4.read();
    cf4.write();
    cf4.execute();
    cout << endl;

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