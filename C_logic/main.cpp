#include "Parser.h"
#include "Constructor.h"
#include "gtest/gtest.h"


TEST(correctness, empty) {
    auto x = std::istringstream("");
    Parser parser(x);
    EXPECT_NO_THROW(parser.parse());
}


TEST(correctness, wrongBrackets1) {
    auto x = std::istringstream(")");
    Parser parser(x);
    EXPECT_THROW(parser.parse(), std::runtime_error);
}

TEST(correctness, wrongBrackets2) {
    auto x = std::istringstream("( a  | b");
    Parser parser(x);
    EXPECT_THROW(parser.parse(), std::runtime_error);
}

TEST(correctness, wrongSymbols1) {
    auto x = std::istringstream("( a  || b)");
    Parser parser(x);
    EXPECT_THROW(parser.parse(), std::runtime_error);
}

TEST(correctness, wrongSymbols2) {
    auto x = std::istringstream("( ab  | b)");
    Parser parser(x);
    EXPECT_THROW(parser.parse(), std::runtime_error);
}

TEST(correctness, weirdSymbols1) {
    auto x = std::istringstream("( a \r | \t \n b)");
    Parser parser(x);
    EXPECT_NO_THROW(parser.parse());
}

TEST(correctness, weirdSymbols2) {
    auto x = std::istringstream("( a \r &!b | \t \n b)");
    Parser parser(x);
    EXPECT_NO_THROW(parser.parse());
}

TEST (correctness, longString1) {
    auto x = std::istringstream("(!a | b) & a & (a | !(b ^ c))");
    Parser parser(x);
    auto res = parser.parse();
    parser.print_tree(res.get());
    EXPECT_NO_THROW(parser.parse());
}


TEST (correctness, custom) {
    auto x = std::istringstream("a | b | c");
    Parser parser(x);
    auto res = parser.parse();
    parser.print_tree(res.get());
    EXPECT_NO_THROW(parser.parse());
}

TEST (correctness, longString2) {
    auto x = std::istringstream("(!a | b) & a & (a | !(b ^ c)) | !!!(c)");
    Parser parser(x);
    EXPECT_NO_THROW(parser.parse());
}


TEST (correctness, longStringRandom) {
    for (int i = 0; i < 1000; ++i) {
        auto str = Constructor::getRandomExpression();
        auto x = std::istringstream(str);
        Parser parser(x);
        EXPECT_NO_THROW(parser.parse());
    }
}