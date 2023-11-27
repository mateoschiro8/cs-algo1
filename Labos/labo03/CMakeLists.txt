cmake_minimum_required(VERSION 3.23)
project(labo03)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(labo03
        src/generador.cpp
        src/generador.h
        src/main.cpp
        src/vectores.cpp
        src/vectores.h
        src/entradaSalida.cpp
        src/entradaSalida.h)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR})
