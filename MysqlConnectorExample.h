//sudo apt install libmysqlcppconn-dev


#ifndef CPPEXAMPLES_MYSQLCONNECTOREXAMPLE_H
#define CPPEXAMPLES_MYSQLCONNECTOREXAMPLE_H

#include <mysql_connection.h>
#include <mysql_driver.h>

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>


#include <iostream>
#include <sstream>
#include <string>

#include <vector>

using namespace std ;


class MysqlConnectorExample {
public:
  void example1();
};


#endif //CPPEXAMPLES_MYSQLCONNECTOREXAMPLE_H
