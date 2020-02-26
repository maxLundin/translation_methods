cmake_minimum_required(VERSION 3.10)
project(Parsing)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(Lexer)
add_subdirectory(Parser)

include_directories(gtest)
include_directories(.)

add_executable(generate_2nd main_2nd.cpp)

add_executable(generate_expr main_expr.cpp)


target_link_libraries(generate_2nd Generator_lexer Generator_parser)
target_link_libraries(generate_expr Generator_lexer Generator_parser)

add_library(gtest gtest/gtest.h gtest/gtest-all.cc gtest/gtest_main.cc)

add_executable(2nd_task 2nd/main.cpp 2nd/parser.cpp 2nd/parser.h 2nd/lexer.cpp 2nd/lexer.h ../C_logic/Constructor.cpp)
target_link_libraries(2nd_task gtest -lpthread)

add_executable(expr_task expr/main.cpp expr/parser.cpp expr/parser.h expr/lexer.cpp expr/lexer.h)
target_link_libraries(expr_task gtest -lpthread)
