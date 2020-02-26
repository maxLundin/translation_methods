#include <bits/stdc++.h>

 enum Token{
NUMBER,
OR,
XOR,
AND,
NOT,
LB,
RB,
GENERATOR_END
};
void scan_string(const std::string& m_tmp_variable);
Token getToken();
std::string  getStr();
