cmake_minimum_required(VERSION 3.7)
project(CppExamples)

set(CMAKE_CXX_STANDARD 11)
set(TARGET_NAME CppExamples)

#list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/foo)
##find_package(MySQL COMPONENTS REQUIRED)
##include_directories(${MySQL_INCLUDE_DIR})
#find_package(MySQLCppConn 1.1.8 REQUIRED)
#find_package(MySQL REQUIRED)
#include_directories(${MySQL_INCLUDE_DIRS})

#execute_process(COMMAND mysql_config --cflags
#        OUTPUT_VARIABLE MYSQL_CFLAGS)
#execute_process(COMMAND mysql_config --libs
#        OUTPUT_VARIABLE MYSQL_LIBS)
#
##target_compile_options(cgm ${MYSQL_CFLAGS})
#SET( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GCC_MYSQL_COMPILE_FLAGS}" )
##target_link_libraries(CppExamples ${MYSQL_LIBS})
#
#
#include_directories(${MYSQL_INCLUDE_DIR})
#target_link_libraries(CppExamples ${MYSQL_LIB})

#target_link_libraries(CppExamples ${MySQL_LIBRARIES})

find_package(Qt5Widgets REQUIRED)
set(SOURCE_FILES main.cpp Person.cpp Person.h PersonDAO.cpp PersonDAO.h ComplexNumber.cpp ComplexNumber.h Box.cpp Box.h OperatorsExample.cpp OperatorsExample.h InheritanceExample.cpp InheritanceExample.h MysqlConnectorExample.cpp MysqlConnectorExample.h QtExamples.cpp QtExamples.h)
add_executable(CppExamples ${SOURCE_FILES})
target_link_libraries(CppExamples mysqlcppconn)
target_link_libraries(CppExamples Qt5::Widgets)