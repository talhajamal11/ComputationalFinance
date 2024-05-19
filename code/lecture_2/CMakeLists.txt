cmake_minimum_required(VERSION 3.27)
project(lecture_2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(lecture_2
        BinModel02.cpp
        BinModel02.h
        Options05.h
        Options05.cpp
        DefInt.cpp
        DefInt.h
        Options06.h
        Options06.cpp
        Main10.cpp
        DoubDigitOpt.h
        DoubDigitOpt.cpp)
