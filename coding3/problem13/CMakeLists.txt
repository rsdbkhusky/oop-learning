cmake_minimum_required(VERSION 3.29)
project(problem13)

set(CMAKE_CXX_STANDARD 17)

add_executable(problem13 main.cpp
        Role.cpp
        Role.h
        Box.cpp
        Box.h
        Solider.cpp
        Solider.h
        Mage.cpp
        Mage.h
        BoxMoney.cpp
        BoxMoney.h
        BoxToxin.cpp
        BoxToxin.h)
