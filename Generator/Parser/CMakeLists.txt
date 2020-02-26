cmake_minimum_required(VERSION 2.8)
project(Parsing)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(parser_parser)

add_library(Generator_parser ParserGen.cpp ParserGen.h)

target_link_libraries(Generator_parser parser_parser)