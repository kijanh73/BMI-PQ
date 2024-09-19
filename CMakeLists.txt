cmake_minimum_required(VERSION 3.26)
project(supershy)

set(CMAKE_CXX_STANDARD 17)

add_executable(supershy main.cpp
        PQ.h
        PQ.cpp)
