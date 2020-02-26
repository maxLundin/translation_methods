#include <bits/stdc++.h>

 enum Token{
NUMBER,
ADD,
SUB,
DIV,
MUL,
LB,
RB,
POW,
GENERATOR_END
};
void scan_string(const std::string& m_tmp_variable);
Token getToken();
std::string  getStr();
