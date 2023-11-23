cmake_minimum_required(VERSION 3.26)
project(TME7)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(TME7
        src/chat_common.h
        src/prod_cons.cpp
        src/Stack.h
        src/pipe.cpp
)

# Link rt and pthread libraries
target_link_libraries(TME7 rt pthread)
