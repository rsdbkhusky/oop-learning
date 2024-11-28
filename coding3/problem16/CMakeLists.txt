cmake_minimum_required(VERSION 3.29)
project(problem16)

set(CMAKE_CXX_STANDARD 17)

add_executable(problem16 main.cpp
        Missile.cpp
        Missile.h
        LaunchMode.cpp
        LaunchMode.h
        FlyBehavior.cpp
        FlyBehavior.h
        SeaLaunch.cpp
        SeaLaunch.h
        AirLaunch.cpp
        AirLaunch.h
        LandLaunch.cpp
        LandLaunch.h
        SubSonicFly.cpp
        SubSonicFly.h
        SuperSonicFly.cpp
        SuperSonicFly.h)
