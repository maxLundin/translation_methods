//
// Created by maxlun on 12/22/19.
//

#include "ParserGen.h"
#include "parser_parser/expression.tab.hpp"
#include "parser_parser/lexer_parser.hpp"

extern Parser_grammar *result_parser;
extern std::string raw_text;
extern std::vector<Rule> rules;
extern std::string type;
extern std::pair<std::string, std::string> derived_attr;


void parser_error(const char *error) {
    cerr << error;
}

int parser_wrap() {
    return 1;
}

std::string replace(const std::string &str, char sub, const std::string &new_str) {
    std::string ret;
    for (const char &a:  str) {
        if (a == sub) {
            ret += new_str;
        } else {
            ret += a;
        }
    }
    return ret;
}


PARSER_CLASS ParserGen::Generate(const std::string &input, const std::string &file_name) {
    PARSER_CLASS lexer{};
    parser__scan_string(input.c_str());
    parser_parse();

    std::string derived_type = derived_attr.first + " " + derived_attr.second;

    for (auto &a: rules) {
        std::cout << a.name << ": ";
        for (auto &b : a.rules) {
            std::cout << b << " ";
        }
        std::cout << std::endl;
    }

    std::set<std::string> ne_term;
    for (auto &a: rules) {
        ne_term.insert(a.name);
    }
    std::set<std::string> term;
    for (auto &a: rules) {
        for (auto &b : a.rules) {
            if (ne_term.find(b) == ne_term.end()) {
                term.insert(b);
            }
        }
    }

    auto fst = first(rules, ne_term);

    std::cout << std::endl;
    for (auto &a : fst) {
        std::cout << a.first << " : ";
        for (auto &b : a.second) {
            if (b.empty()) {
                std::cout << "epsilon" << " ";
            } else {
                std::cout << b << " ";
            }
        }
        std::cout << std::endl;
    }

    auto flw = follow(rules, ne_term, fst);

    std::cout << std::endl;
    for (auto &a : flw) {
        std::cout << a.first << " : ";
        for (auto &b : a.second) {
            if (b.empty()) {
                std::cout << "epsilon" << " ";
            } else {
                std::cout << b << " ";
            }
        }
        std::cout << std::endl;
    }

    lexer.cpp += "#include <bits/stdc++.h>\n"
                 "#include \"lexer.h\"\n"
                 "#include \"";
    lexer.cpp += file_name;
    lexer.cpp += ".h\"\n"
                 "\n";
    lexer.h += raw_text;
    lexer.cpp += "using namespace std;\n"
                 "\n"
                 "Token cur_token;\n"
                 "\n";
    lexer.cpp += type;
    lexer.cpp += " parse(){\n";
    lexer.cpp += derived_type;
    lexer.cpp += "{};\ncur_token = getToken();\n return ";
    lexer.cpp += rules[0].name;
    lexer.cpp += "(";
    lexer.cpp += derived_attr.second;
    lexer.cpp += ");\n}\n";

    lexer.h += type;
    lexer.h += " parse();\n";


    auto getFirst = [&](const std::vector<string> &rul) -> std::unordered_set<std::string> {
        std::unordered_set<std::string> ret{};
        for (const auto &item : rul) {
            ret.insert(fst[item].begin(), fst[item].end());
            if (fst[item].find("") == fst[item].end()) {
                break;
            }
        }
        return ret;
    };

    auto get_rule = [&](const std::string &token, const std::string &net) -> size_t {
        size_t number = 0;
        for (auto &a : rules) {
            if (a.name == net) {
                if (!a.rules.empty() && a.rules[0] == token) {
                    return number;
                }
                if (!a.rules.empty()) {
                    auto frst = getFirst(a.rules);
                    if (frst.find(token) != frst.end()) {
                        return number;
                    }
                }
                if (a.rules.empty() && token.empty()) {
                    return number;
                }
            }
            ++number;
        }
        throw std::runtime_error("no_rule_found");
    };

    for (auto &net : ne_term) {
        lexer.cpp += type;
        lexer.cpp += " ";
        lexer.cpp += net;
        lexer.cpp += " (";
        lexer.cpp += derived_type;
        lexer.cpp += "){\n";
        lexer.h += type;
        lexer.h += " ";
        lexer.h += net;
        lexer.h += " (";
        lexer.h += derived_type;
        lexer.h += ");\n";

        lexer.cpp += type;
        lexer.cpp += " valval;\n";

        bool need_flw = false;
        for (auto &token : fst[net]) {
            if (token.empty()) {
                need_flw = true;
                continue;
            }
            lexer.cpp += "if (cur_token == ";
            lexer.cpp += token;
            lexer.cpp += " ){\n";
            size_t rule_number = get_rule(token, net);
            auto template_str = replace(rules[rule_number].code, '$', "val");

            size_t number = 0;
            std::string res_str;
            for (size_t i = 0; i < template_str.size(); ++i) {
                if (template_str[i] == '!') {
                    number++;
                    res_str += "auto val";
                    res_str += std::to_string(number);
                    res_str += " = ";
                    auto &a = rules[rule_number].rules[number - 1];

                    if (!('0' <= template_str[++i] && template_str[++i] <= '9')) {
                        throw std::runtime_error("wrong ! format");
                    }
                    while ('0' <= template_str[i] && template_str[i] <= '9') {
                        ++i;
                    }

                    if (term.find(a) == term.end()) {
                        res_str += a;
                        res_str += "(";
                        res_str += derived_attr.second;
                        res_str += ");";
                    } else {
                        res_str += "getStr();\n"
                                   "if ( cur_token != ";
                        res_str += a;
                        res_str += "){ throw std::runtime_error(\"syntax error\"); }";

                        res_str += "cur_token = getToken();\n";
                    }

                } else {
                    res_str += template_str[i];
                }
            }

            lexer.cpp += res_str;

            lexer.cpp += "return valval;\n";
            lexer.cpp += "}\n";
        }
        if (need_flw) {
            lexer.cpp += "if (";
            for (auto &token : flw[net]) {
                if (token.empty()) {
                    continue;
                }
                if (token == "$") {
                    lexer.cpp += " cur_token == ";
                    lexer.cpp += "GENERATOR_END";
                    lexer.cpp += " ||";
                    continue;
                }
                lexer.cpp += " cur_token == ";
                lexer.cpp += token;
                lexer.cpp += " ||";
            }
            lexer.cpp.pop_back();
            lexer.cpp.pop_back();
            lexer.cpp += ") {";
            lexer.cpp += replace(rules[get_rule("", net)].code, '$', "val");
            lexer.cpp += "return valval;\n";
            lexer.cpp += "}";
        }
        lexer.cpp += "else {\n"
                     "  throw std::runtime_error(\"syntax error\");\n }";
        lexer.cpp += "}\n";
    }


    return lexer;
}

std::unordered_map<std::string, std::unordered_set<std::string>>
ParserGen::first(const std::vector<Rule> &m_rules, const std::set<std::string> &ne_term) {
    std::unordered_map<std::string, std::unordered_set<std::string>> first;

    for (auto &a: m_rules) {
        for (auto &b : a.rules) {
            if (ne_term.find(b) != ne_term.end()) {
                first.insert(std::make_pair(b, std::unordered_set<std::string>{}));
            } else {
                first.insert(std::make_pair(b, std::unordered_set<std::string>{b}));
            }
        }
    }

    for (auto &a: m_rules) {
        if (ne_term.find(a.name) != ne_term.end()) {
            if (a.rules.empty()) {
                if (auto ptr = first.find(a.name); ptr != first.end()) {
                    first[a.name].insert("");
                } else {
                    first.insert(std::make_pair(a.name, std::unordered_set<std::string>{""}));
                }
            } else {
                first.insert(std::make_pair(a.name, std::unordered_set<std::string>{}));
            }
        } else {
            first.insert(std::make_pair(a.name, std::unordered_set<std::string>{a.name}));
        }
    }
    auto getFirst = [&](const std::vector<string> &rul) -> std::unordered_set<std::string> {
        std::unordered_set<std::string> ret{};
        for (const auto &item : rul) {
            ret.insert(first[item].begin(), first[item].end());
            if (first[item].find("") == first[item].end()) {
                break;
            }
        }
        return ret;
    };
    bool changed = true;
    while (changed) {
        changed = false;
        for (auto &a: m_rules) {
            size_t prev_size = first[a.name].size();
            auto lp_first = getFirst(a.rules);
            first[a.name].insert(lp_first.begin(), lp_first.end());
            if (prev_size != first[a.name].size()) {
                changed = true;
            }
        }
    }
    return first;
}


std::unordered_map<std::string, std::unordered_set<std::string>>
ParserGen::follow(const std::vector<Rule> &m_rules, const std::set<std::string> &ne_term,
                  std::unordered_map<std::string, std::unordered_set<std::string>> &first) {
    std::unordered_map<std::string, std::unordered_set<std::string>> follow;

    for (auto &a: m_rules) {
        for (auto &b : a.rules) {
            follow.insert(std::make_pair(b, std::unordered_set<std::string>{}));
        }
        follow.insert(std::make_pair(a.name, std::unordered_set<std::string>{}));
    }

    follow[m_rules[0].name].insert("$");

    auto getFirst = [&](const std::vector<string> &rul, size_t pos) -> std::unordered_set<std::string> {
        std::unordered_set<std::string> ret{};
        for (size_t i = pos; i < rul.size(); ++i) {
            ret.insert(first[rul[i]].begin(), first[rul[i]].end());
            if (first[rul[i]].find("") == first[rul[i]].end()) {
                break;
            }
        }
        return ret;
    };
    bool changed = true;
    while (changed) {
        changed = false;
        for (auto &a: m_rules) {
            for (size_t i = 0; i < a.rules.size(); ++i) {
                size_t prev_size = follow[a.rules[i]].size();
                if (i == a.rules.size() - 1) {
                    follow[a.rules[i]].insert(follow[a.name].begin(), follow[a.name].end());
                } else {
                    auto fst = getFirst(a.rules, i + 1);
                    if (fst.find("") != fst.end()) {
                        follow[a.rules[i]].insert(follow[a.name].begin(), follow[a.name].end());
                    }
                    fst.erase("");
                    follow[a.rules[i]].insert(fst.begin(), fst.end());
                }
                if (prev_size != follow[a.rules[i]].size()) {
                    changed = true;
                }
            }
        }
    }
    return follow;
}

