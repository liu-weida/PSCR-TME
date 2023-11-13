cmake_minimum_required(VERSION 3.26)
project(TME6)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(TME6
        src/fork_exo.cpp
        src/rsleep.cpp
        src/rsleep.h
        src/combat.cpp
        src/wait.cpp)
