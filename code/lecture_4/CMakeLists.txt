cmake_minimum_required(VERSION 3.27)
project(lecture_4)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(lecture_4
        EurCall.cpp
        EurCall.h
        Main15.cpp
        Main16.cpp
        Main17.cpp
        Main18.cpp
        Solver01.h
        Solver02.h
        Solver03.h)
