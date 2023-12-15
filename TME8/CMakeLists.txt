cmake_minimum_required(VERSION 3.26)
project(TME8)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(TME8
        src/client.cpp
        src/server.cpp
        src/server2.cpp
        src/ServerSocket.h
        src/ServerSocket.cpp
        src/Socket.h
        src/Socket.cpp)
