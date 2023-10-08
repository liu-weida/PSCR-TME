cmake_minimum_required(VERSION 3.26)
project(TME2)

set(CMAKE_CXX_STANDARD 14)


include_directories(src)

add_executable(TME2_Q1 src/TME2_Q1.cpp)
add_executable(TME2_Q2 src/TME2_Q2.cpp)
add_executable(TME2_Q3 src/TME2_Q3.cpp)
add_executable(TME2_Q6 src/TME2_Q6.cpp)
add_executable(TME2_Q7 src/TME2_Q7.cpp)
add_executable(TME2_Q8 src/TME2_Q8.cpp)

add_executable(TME3_Q123 src/TME3_Q123.cpp)

add_executable(HashMap src/HashMap.cpp src/HashMap.h)
