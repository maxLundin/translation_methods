//
// Created by maxlun on 10/4/19.
//

#pragma once

#include <string>

class Constructor {
public:
    static std::string getRandomExpression(bool number);

private:

    static void E(std::string &, size_t depth);
    static void X(std::string &, size_t depth);
    static void A(std::string &, size_t depth);
    static void N(std::string &, size_t depth);
    static void B(std::string &, size_t depth);
    static int get_random_int();
};


