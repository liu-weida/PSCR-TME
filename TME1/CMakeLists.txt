cmake_minimum_required(VERSION 3.26)
project(TME1)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(TME1
        src/String.cpp
        src/String.h
        src/tme.cpp)
