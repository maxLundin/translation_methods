//
// Created by maxlun on 12/22/19.
//

#include "gtest.h"

#include "lexer.h"
#include "parser.h"

int main() {
    scan_string("2**2**4 ");
    std::cout << parse();
}