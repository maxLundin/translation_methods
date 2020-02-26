//
// Created by maxlun on 12/22/19.
//

#include "gtest.h"

#include "lexer.h"
#include "parser.h"
#include "../../C_logic/Constructor.h"


TEST(correctness, simple) {
    std::string in = "4";
    scan_string(in);
    EXPECT_NO_THROW(parse());
}


TEST(correctness, wrongBrackets1) {
    auto x = std::string(")");
    scan_string(x);
    EXPECT_THROW(parse(), std::runtime_error);
}

TEST(correctness, wrongBrackets2) {
    auto x = std::string("( 100  | 23");
    scan_string(x);
    EXPECT_THROW(parse(), std::runtime_error);
}

TEST(correctness, wrongSymbols1) {
    auto x = std::string("( 111  || 23)");
    scan_string(x);
    EXPECT_THROW(parse(), std::runtime_error);
}

TEST(correctness, wrongSymbols2) {
    auto x = std::string("( 44  | 1 422)");
    scan_string(x);
    EXPECT_THROW(parse(), std::runtime_error);
}

TEST(correctness, weirdSymbols1) {
    auto x = std::string("( 12 \r | \t \n 7)");
    scan_string(x);
    EXPECT_NO_THROW(parse());
}

TEST(correctness, weirdSymbols2) {
    auto x = std::string("( 43 \r &!1 | \t \n 5)");
    scan_string(x);
    EXPECT_NO_THROW(parse());
}

TEST (correctness, longString1) {
    auto x = std::string("(!4 | 12) & 33 & (5 | !(6 ^ 4))");
    scan_string(x);
    EXPECT_NO_THROW(parse());
}


TEST (correctness, custom) {
    auto x = std::string("532 | 66 | 234");
    scan_string(x);
    EXPECT_NO_THROW(parse());
}

TEST (correctness, longString2) {
    auto x = std::string("(!1234 | 545) & 888 & (65 | !(345 ^ 999)) | !!!(0)");
    scan_string(x);
    EXPECT_NO_THROW(parse());
}


TEST (correctness, longStringRandom) {
    for (int i = 0; i < 100; ++i) {
        auto x = Constructor::getRandomExpression(true);
//        std::cout << x << std::endl;
        scan_string(x);
        EXPECT_NO_THROW(parse());
    }
}
