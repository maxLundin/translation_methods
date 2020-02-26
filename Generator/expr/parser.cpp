#include <bits/stdc++.h>
#include "lexer.h"
#include "/home/maxlun/Documents/Parcing/Generator/expr/parser.h"

using namespace std;

Token cur_token;

int32_t parse() {
    int32_t num{};
    cur_token = getToken();
    return E(num);
}

int32_t B(int32_t num) {
    int32_t valval;
    if (cur_token == LB) {
        auto val1 = P(num);
        auto val2 = BB(num);
        valval = pow1(val1, val2);
        return valval;
    }
    if (cur_token == NUMBER) {
        auto val1 = P(num);
        auto val2 = BB(num);
        valval = pow1(val1, val2);
        return valval;
    } else {
        throw std::runtime_error("syntax error");
    }
}

int32_t BB(int32_t num) {
    int32_t valval;
    if (cur_token == POW) {
        auto val1 = getStr();
        if (cur_token != POW) { throw std::runtime_error("syntax error"); }
        cur_token = getToken();
        auto val2 = P(num);
        auto val3 = BB(num);
        valval = pow1(val2, val3);
        return valval;
    }
    if (cur_token == RB || cur_token == SUB || cur_token == MUL || cur_token == GENERATOR_END || cur_token == DIV ||
        cur_token == ADD) {
        valval = 1;
        return valval;
    } else {
        throw std::runtime_error("syntax error");
    }
}

int32_t E(int32_t num) {
    int32_t valval;
    if (cur_token == LB) {
        auto val1 = X(num);
        num = val1;
        auto val2 = EE(num);
        valval = val2;
        return valval;
    }
    if (cur_token == NUMBER) {
        auto val1 = X(num);
        num = val1;
        auto val2 = EE(num);
        valval = val2;
        return valval;
    } else {
        throw std::runtime_error("syntax error");
    }
}

int32_t EE(int32_t num) {
    int32_t valval;
    if (cur_token == SUB) {
        auto val1 = getStr();
        if (cur_token != SUB) { throw std::runtime_error("syntax error"); }
        cur_token = getToken();
        uint32_t v = num;
        auto val2 = X(num);
        v -= val2;
        num = v;
        auto val3 = EE(num);
        valval = val3;
        return valval;
    }
    if (cur_token == ADD) {
        auto val1 = getStr();
        if (cur_token != ADD) { throw std::runtime_error("syntax error"); }
        cur_token = getToken();
        uint32_t v = num;
        auto val2 = X(num);
        v += val2;
        num = v;
        auto val3 = EE(num);
        valval = val3;
        return valval;
    }
    if (cur_token == RB || cur_token == GENERATOR_END) {
        valval = num;
        return valval;
    } else {
        throw std::runtime_error("syntax error");
    }
}

int32_t P(int32_t num) {
    int32_t valval;
    if (cur_token == LB) {
        auto val1 = getStr();
        if (cur_token != LB) { throw std::runtime_error("syntax error"); }
        cur_token = getToken();
        auto val2 = E(num);
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

int32_t X(int32_t num) {
    int32_t valval;
    if (cur_token == LB) {
        auto val1 = B(num);
        num = val1;
        auto val2 = XX(num);
        valval = val2;
        return valval;
    }
    if (cur_token == NUMBER) {
        auto val1 = B(num);
        num = val1;
        auto val2 = XX(num);
        valval = val2;
        return valval;
    } else {
        throw std::runtime_error("syntax error");
    }
}

int32_t XX(int32_t num) {
    int32_t valval;
    if (cur_token == DIV) {
        auto val1 = getStr();
        if (cur_token != DIV) { throw std::runtime_error("syntax error"); }
        cur_token = getToken();
        uint32_t v = num;
        auto val2 = B(num);
        v /= val2;
        num = v;
        auto val3 = XX(num);
        valval = val3;
        return valval;
    }
    if (cur_token == MUL) {
        auto val1 = getStr();
        if (cur_token != MUL) { throw std::runtime_error("syntax error"); }
        cur_token = getToken();
        uint32_t v = num;
        auto val2 = B(num);
        v *= val2;
        num = v;
        auto val3 = XX(num);
        valval = val3;
        return valval;
    }
    if (cur_token == RB || cur_token == GENERATOR_END || cur_token == ADD || cur_token == SUB) {
        valval = num;
        return valval;
    } else {
        throw std::runtime_error("syntax error");
    }
}
