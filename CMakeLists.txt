cmake_minimum_required(VERSION 3.14)
project(Program2Source)

set(CMAKE_CXX_STANDARD 14)

add_executable(Program2Source consistentresultverification.cxx createdata.cxx insertionsort.cpp insertionsort.h json.hpp mergesort.cpp mergesort.h quicksort.cpp quicksort.h sortedverification.cxx timealgorithms.cxx)