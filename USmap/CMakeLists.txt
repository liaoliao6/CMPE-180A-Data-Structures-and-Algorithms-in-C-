cmake_minimum_required(VERSION 3.15)
project(USmap)

set(CMAKE_CXX_STANDARD 11)

add_executable(USmap MapMaker.cpp SortedLinkedList.h Node.h City.h City.cpp Coordinate.cpp Coordinate.h Node.cpp SortedLinkedList.cpp)