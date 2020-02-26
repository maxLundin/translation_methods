//
// Created by maxlun on 10/4/19.
//

#include <random>
#include "Constructor.h"

static bool numbers = false;

std::string Constructor::getRandomExpression(bool number = false) {
    std::string res;
    numbers = number;
    E(res, 0);
    return res;
}

void Constructor::E(std::string &res, size_t depth) {
    int t = get_random_int();
    if (t % 3 == 0 && depth < 100) {
        E(res, depth + 1);
        res += '|';
        X(res, depth + 1);
    } else {
        X(res, depth + 1);
    }
}

void Constructor::X(std::string &res, size_t depth) {
    int t = get_random_int();
    if (t % 3 == 0 && depth < 100) {
        X(res, depth + 1);
        res += '^';
        A(res, depth + 1);
    } else {
        A(res, depth + 1);
    }
}

void Constructor::A(std::string &res, size_t depth) {
    int t = get_random_int();
    if (t % 3 == 0 && depth < 100) {
        A(res, depth + 1);
        res += '&';
        N(res, depth + 1);
    } else {
        N(res, depth + 1);
    }
}

void Constructor::N(std::string &res, size_t depth) {
    int t = get_random_int();
    if (t % 3 == 0 && depth < 100) {
        res += '!';
        N(res, depth + 1);
    } else {
        B(res, depth + 1);
    }
}

void Constructor::B(std::string &res, size_t depth) {
    int t = get_random_int();
    if (t % 3 == 0 && depth < 100) {
        res += '(';
        E(res, depth + 1);
        res += ')';
    } else {
        if (!numbers) {
            res += ('a' + t % 25);
        } else {
            res += ('0' + t % 10);
        }
    }
}

int Constructor::get_random_int() {
    std::random_device rd;
    std::uniform_int_distribution<int> dist(0, 100);
    return dist(rd);
}
