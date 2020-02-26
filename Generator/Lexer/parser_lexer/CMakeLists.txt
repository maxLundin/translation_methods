cmake_minimum_required(VERSION 3.7)
project(parser_lexer)


set(CMAKE_CXX_STANDARD 17)

find_package(BISON REQUIRED)
find_package(FLEX REQUIRED)

BISON_TARGET(MyParser expr_lexer.y ${PROJECT_SOURCE_DIR}/expression.tab.cpp)
FLEX_TARGET(MyScanner expr_lexer.l ${PROJECT_SOURCE_DIR}/lexer_parser.cpp)
ADD_FLEX_BISON_DEPENDENCY(MyScanner MyParser)

add_library(lexer_parser
        lexer.h
        ${BISON_MyParser_OUTPUTS}
        ${FLEX_MyScanner_OUTPUTS})