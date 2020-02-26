cmake_minimum_required(VERSION 3.7)
project(Test)


set(CMAKE_CXX_STANDARD 17)

find_package(BISON REQUIRED)
find_package(FLEX REQUIRED)

BISON_TARGET(MyParser expression.y ${PROJECT_SOURCE_DIR}/expression.tab.cpp)
FLEX_TARGET(MyScanner expression.l ${PROJECT_SOURCE_DIR}/expression.lexer.cpp)
ADD_FLEX_BISON_DEPENDENCY(MyScanner MyParser)

add_executable(Test
        main.cpp
        ${BISON_MyParser_OUTPUTS}
        ${FLEX_MyScanner_OUTPUTS})