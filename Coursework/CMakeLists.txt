cmake_minimum_required(VERSION 3.27)
project(Coursework)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(Coursework
        src/conjgrad.m
        src/csv.cpp
        src/csv.h
        src/read_data.cpp
        src/testSolutions.m)
