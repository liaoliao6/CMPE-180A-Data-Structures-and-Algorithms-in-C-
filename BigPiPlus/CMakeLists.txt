cmake_minimum_required(VERSION 3.15)
project(BigPiPlus)

set(CMAKE_CXX_STANDARD 11)

add_executable(BigPiPlus bigpiplus.cpp arbitraryprecision.cpp arbitraryprecision.h)

target_link_libraries(BigPiPlus mpir mpirxx)