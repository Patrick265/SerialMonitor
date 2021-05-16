cmake_minimum_required(VERSION 3.16)
project(SerialMonitor)

set(CMAKE_CXX_STANDARD 20)

add_executable(SerialMonitor Main.cpp
        source/Configuration.cpp
        source/SerialMonitor.cpp
        source/ArgumentHandler.cpp
        )


target_include_directories(SerialMonitor PUBLIC include)

