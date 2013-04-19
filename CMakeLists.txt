CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

PROJECT(cpptools C CXX)

ADD_DEFINITIONS(-g -O3 -Wall)

add_executable (test test.cpp)

