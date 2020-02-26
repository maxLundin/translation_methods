//
// Created by maxlun on 10/3/19.
//

#pragma once

#include <memory>
#include <istream>
#include "expression.h"

enum class Token {
    LBRACKET,
    RBRACKET,
    VARIABLE,
    NOT,
    AND,
    XOR,
    OR,
    END,
};

class LexicalAnalyser {
public:
    explicit LexicalAnalyser(std::istream &input) : m_istream(input) {
        cur_pos = 0;
        cur_char = 0;
//        next_token();
    }

    void next_token();

    Token get_token();

    char get_char();

    int get_position();

    void next_char();

private:

    bool is_whilespace();


    std::istream &m_istream;
    char cur_char;
    Token cur_token;
    size_t cur_pos;
};

class Parser {
    LexicalAnalyser lexical_analyser;
public:
    explicit Parser(std::istream &is) : lexical_analyser(is) {
//        lexical_analyser.next_char();
    }

    std::unique_ptr<Node> parse();

    void print_tree(Node *ptr);

private:
    void go_print(Node * ptr , size_t depth);
    std::unique_ptr<Node> E();

    std::unique_ptr<Node> Er();

    std::unique_ptr<Node> X();

    std::unique_ptr<Node> Xr();

    std::unique_ptr<Node> A();

    std::unique_ptr<Node> Ar();

    std::unique_ptr<Node> N();

    std::unique_ptr<Node> B();
};