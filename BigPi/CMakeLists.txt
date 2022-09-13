cmake_minimum_required(VERSION 3.15)
project(BigPi)

set(CMAKE_CXX_STANDARD 11)

add_executable(BigPi bigpic.cpp)

target_link_libraries(BigPi mpir mpirxx)