cmake_minimum_required(VERSION 3.15)
project(STLVL)

set(CMAKE_CXX_STANDARD 11)

add_executable(STLVL TestDriver.cpp SortedList.cpp SortedList.h SortedVector.cpp SortedVector.h TestSuite.cpp TestSuite.h Node.cpp Node.h Timer.cpp Timer.h)