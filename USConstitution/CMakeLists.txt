cmake_minimum_required(VERSION 3.16)
project(USConstitution)

set(CMAKE_CXX_STANDARD 11)

add_executable(USConstitution Constitution.cpp WordList.cpp WordList.h WordMap.cpp WordMap.h WordVector.cpp WordVector.h Word.h TimedContainer.h)