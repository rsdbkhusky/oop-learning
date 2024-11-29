cmake_minimum_required(VERSION 3.29)
project(problem19)

set(CMAKE_CXX_STANDARD 17)

add_executable(problem19 main.cpp
        Farm.cpp
        Farm.h
        Data.h
        MethodForecastAmout.h
        MethodForecastAmout.cpp
        MethodForecastPrice.cpp
        MethodForecastPrice.h
        MethodSolveResult.cpp
        MethodSolveResult.h
        MethodForecastAmoutA.cpp
        MethodForecastAmoutA.h
        MethodForecastAmoutB.cpp
        MethodForecastAmoutB.h)
