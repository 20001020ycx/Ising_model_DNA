cmake_minimum_required(VERSION 3.17)
project(DNA_Ising_Model)

set(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_FLAGS -pthread)
SET(CMAKE_CXX_FLAGS -lX11)

add_compile_options(-Wall)

add_executable(DNA_Ising_Model main.cpp utility.h utility.cpp Input_Output.h Input_Output.cpp image.h image.cpp image.cpp image.cpp image.cpp Ising_Procedure.h Ising_Procedure.cpp)

