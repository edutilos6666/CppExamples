cmake_minimum_required(VERSION 3.7)
project(CppExamples)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Person.cpp Person.h PersonDAO.cpp PersonDAO.h ComplexNumber.cpp ComplexNumber.h Box.cpp Box.h OperatorsExample.cpp OperatorsExample.h)
add_executable(CppExamples ${SOURCE_FILES})