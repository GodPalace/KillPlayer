cmake_minimum_required(VERSION 3.28)
project(TEST)

set(CMAKE_CXX_STANDARD 26)

add_executable(TEST
        exploit.cpp
        include/STACK.h
        include/QUEUE.h
        dome/dome_in.cpp
        include/ROUND_ROBIN_QUEUE.h
        include/LINK.h
        include/WHEIL_LINK.h
        tree.cpp
)
