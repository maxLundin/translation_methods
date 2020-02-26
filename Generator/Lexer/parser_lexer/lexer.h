//
// Created by maxlun on 12/20/19.
//

#ifndef PARSING_LEXER_H
#define PARSING_LEXER_H

#include <bits/stdc++.h>

struct Lexer {
    std::string raw;
    std::vector<std::pair<std::string, std::string>> data;
    std::string left;
    std::vector<std::string> tokens;
    std::vector<std::string> skips;

    void append(Lexer *a) {
        for (const auto &i : a->data) {
            this->data.push_back(i);
        }
    }
    Lexer() {

    }

    explicit Lexer(const std::string &a) {
        left = a;
    }

    void add_skip(Lexer * a){
        skips.push_back(a->left);
    }

    friend Lexer *combine(Lexer *a, Lexer *b);

    friend Lexer *final_combine(Lexer *a, Lexer *b, Lexer *c);
};

inline Lexer *combine(Lexer *a, Lexer *b) {
    auto gg = new Lexer("");
    gg->data.emplace_back(a->left, b->left);
    return gg;
}

inline Lexer *final_combine(Lexer *a, Lexer *b, Lexer *c) {
    auto gg = new Lexer("");
    if (a != nullptr) {
        gg->raw = a->raw;
    }
    if (b != nullptr) {
        gg->data = b->data;
    }
    gg->tokens = c->tokens;
    return gg;
}

#endif //PARSING_LEXER_H
