cmake_minimum_required(VERSION 3.15)
project(BookCatalog)

set(CMAKE_CXX_STANDARD 11)

add_executable(BookCatalog Book.h Book.cpp BookApp.cpp)