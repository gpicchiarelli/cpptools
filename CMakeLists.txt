 
CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

PROJECT(cpptools C)

ADD_DEFINITIONS(-g -O3 -fsigned-char -freg-struct-return -Wall -W -Wshadow -Wstrict-prototypes -Wpointer-arith -Wcast-qual -Winline -Werror)

ADD_EXECUTABLE(cpptools.so main.c)