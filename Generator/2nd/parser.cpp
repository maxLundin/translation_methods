#include <bits/stdc++.h>
#include "lexer.h"
#include "/home/maxlun/Documents/Parcing/Generator/2nd/parser.h"

using namespace std;

Token cur_token;

uint32_t parse() {
    {};
    cur_token = getToken();
    return E();
}

uint32_t A() {
    uint32_t valval;
    if (cur_token == LB) {
        auto val1 = N();
        auto val2 = AA();
        valval = val1 & val2;
        return valval;
    }
    if (cur_token == NUMBER) {
        auto val1 = N();
        auto val2 = AA();
        valval = val1 & val2;
        return valval;
    }
    if (cur_token == NOT) {
        auto val1 = N();
        auto val2 = AA();
        valval = val1 & val2;
        return valval;
    } else {
        throw std::runtime_error("syntax error");
    }
}

uint32_t AA() {
    uint32_t valval;
    if (cur_token == AND) {
        auto val1 = getStr();
        if (cur_token != AND) { throw std::runtime_error("syntax error"); }
        cur_token = getToken();
        auto val2 = N();
        auto val3 = AA();
        valval = val2 & val3;
        return valval;
    }
    if (cur_token == RB || cur_token == GENERATOR_END || cur_token == XOR || cur_token == OR) {
        valval = UINT32_MAX;
        return valval;
    } else {
        throw std::runtime_error("syntax error");
    }
}

uint32_t B() {
    uint32_t valval;
    if (cur_token == LB) {
        auto val1 = getStr();
        if (cur_token != LB) { throw std::runtime_error("syntax error"); }
        cur_token = getToken();
        auto val2 = E();
        auto val3 = getStr();
        if (cur_token != RB) { throw std::runtime_error("syntax error"); }
        cur_token = getToken();
        valval = val2;
        return valval;
    }
    if (cur_token == NUMBER) {
        auto val1 = getStr();
        if (cur_token != NUMBER) { throw std::runtime_error("syntax error"); }
        cur_token = getToken();
        valval = a;
        return valval;
    } else {
        throw std::runtime_error("syntax error");
    }
}

uint32_t E() {
    uint32_t valval;
    if (cur_token == LB) {
        auto val1 = X();
        auto val2 = EE();
        valval = val1 | val2;
        return valval;
    }
    if (cur_token == NUMBER) {
        auto val1 = X();
        auto val2 = EE();
        valval = val1 | val2;
        return valval;
    }
    if (cur_token == NOT) {
        auto val1 = X();
        auto val2 = EE();
        valval = val1 | val2;
        return valval;
    } else {
        throw std::runtime_error("syntax error");
    }
}

uint32_t EE() {
    uint32_t valval;
    if (cur_token == OR) {
        auto val1 = getStr();
        if (cur_token != OR) { throw std::runtime_error("syntax error"); }
        cur_token = getToken();
        auto val2 = X();
        auto val3 = EE();
        valval = val2 | val3;
        return valval;
    }
    if (cur_token == RB || cur_token == GENERATOR_END) {
        valval = 0;
        return valval;
    } else {
        throw std::runtime_error("syntax error");
    }
}

uint32_t N() {
    uint32_t valval;
    if (cur_token == LB) {
        auto val1 = B();
        valval = val1;
        return valval;
    }
    if (cur_token == NUMBER) {
        auto val1 = B();
        valval = val1;
        return valval;
    }
    if (cur_token == NOT) {
        auto val1 = getStr();
        if (cur_token != NOT) { throw std::runtime_error("syntax error"); }
        cur_token = getToken();
        auto val2 = N();
        valval = ~val2;
        return valval;
    } else {
        throw std::runtime_error("syntax error");
    }
}

uint32_t X() {
    uint32_t valval;
    if (cur_token == LB) {
        auto val1 = A();
        auto val2 = XX();
        valval = val1 ^ val2;
        return valval;
    }
    if (cur_token == NUMBER) {
        auto val1 = A();
        auto val2 = XX();
        valval = val1 ^ val2;
        return valval;
    }
    if (cur_token == NOT) {
        auto val1 = A();
        auto val2 = XX();
        valval = val1 ^ val2;
        return valval;
    } else {
        throw std::runtime_error("syntax error");
    }
}

uint32_t XX() {
    uint32_t valval;
    if (cur_token == XOR) {
        auto val1 = getStr();
        if (cur_token != XOR) { throw std::runtime_error("syntax error"); }
        cur_token = getToken();
        auto val2 = A();
        auto val3 = XX();
        valval = val2 ^ val3;
        return valval;
    }
    if (cur_token == RB || cur_token == OR || cur_token == GENERATOR_END) {
        valval = 0;
        return valval;
    } else {
        throw std::runtime_error("syntax error");
    }
}
