cmake_minimum_required(VERSION 3.29)
project(problem3)

set(CMAKE_CXX_STANDARD 14)

add_executable(problem3 main.cpp
        NumArray.cpp
        NumArray.h
        NumArrayItem.cpp
        NumArrayItem.h)
