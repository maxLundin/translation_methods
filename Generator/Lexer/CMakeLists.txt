cmake_minimum_required(VERSION 2.8)
project(Parsing)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(parser_lexer)

add_library(Generator_lexer LexGen.cpp LexGen.h)

target_link_libraries(Generator_lexer lexer_parser)