cmake_minimum_required(VERSION 2.8)
project(Parsing)

set(CMAKE_CXX_STANDARD 17)

add_library(GTEST gtest/gtest-all.cc
        gtest/gtest.h
        gtest/gtest_main.cc)

add_library(Parser Parser.cpp Parser.h expression.h)

add_executable(Parsing_testing main.cpp Constructor.cpp Constructor.h)

target_link_libraries(Parsing_testing -lpthread GTEST Parser)