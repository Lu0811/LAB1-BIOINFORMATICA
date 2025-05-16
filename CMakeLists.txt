cmake_minimum_required(VERSION 3.14)
project(BioinformaticsApp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(mainprog
    src/main.cpp
    src/Bioinformatics.cpp
)
