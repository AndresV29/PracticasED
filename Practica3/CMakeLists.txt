cmake_minimum_required(VERSION 3.26)
project(Practica3)

set(CMAKE_CXX_STANDARD 17)

add_executable(Practica3 main.cpp
        Gestor.cpp
        Gestor.h
        Llamada.cpp
        Llamada.h
        PilaLlamadas.cpp
        PilaLlamadas.h)
