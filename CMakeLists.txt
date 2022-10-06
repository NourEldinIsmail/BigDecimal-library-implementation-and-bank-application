cmake_minimum_required(VERSION 3.21)
project(BigDecimal)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(BigDecimal1
        bigDec.cpp
        bigDec.h
        main.cpp)
