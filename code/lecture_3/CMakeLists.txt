cmake_minimum_required(VERSION 3.27)
project(lecture_3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(lecture_3
        BinLattice01.h
        BinLattice02.h
        BinModel02.cpp
        BinModel02.h
        Main12.cpp
        Main13.cpp
        Main14.cpp
        Options07.cpp
        Options07.h
        Options08.cpp
        Options08.h
        Options09.cpp
        Options09.h)
