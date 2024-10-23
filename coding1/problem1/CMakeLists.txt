cmake_minimum_required(VERSION 3.29)
project(coding1)

set(CMAKE_CXX_STANDARD 17)

add_executable(coding1 main.cpp
        MyApp.h
        MyApp.cpp
        CommandParser.cpp
        CommandParser.h
        CommandPara.cpp
        CommandPara.h
        Operation.cpp
        Operation.h
        OperationAdd.cpp
        OperationAdd.h
        OperationRed.cpp
        OperationRed.h
        OperationConcat.cpp
        OperationConcat.h
        OperationHelp.cpp
        OperationHelp.h)
