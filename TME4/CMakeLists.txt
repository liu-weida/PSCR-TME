cmake_minimum_required(VERSION 3.26)
project(TME4)

set(CMAKE_CXX_STANDARD 17)

add_executable(TME4
        src/Banque.cpp
        src/main.cpp
        src/Compte.cpp)

target_link_libraries(TME4 pthread)
