cmake_minimum_required(VERSION 3.23)
project(Desktop)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

include_directories(desktop/LaboAlgo1/labo07)

add_executable(Desktop
        labo07/cases.cpp
        labo07/cases.h
        labo07/ejercicios.cpp
        labo07/ejercicios.h
        labo07/main.cpp)


