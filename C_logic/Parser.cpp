//
// Created by maxlun on 10/3/19.
//

#include <queue>
#include <iostream>
#include <map>
#include "Parser.h"


std::unique_ptr<Node> Parser::E() {
    std::unique_ptr<Node> m_node(new Node("E"));
    m_node->add_children(X());
    m_node->add_children(Er());
    return m_node;
}

std::unique_ptr<Node> Parser::Er() {
    std::unique_ptr<Node> m_node(new Node("E'"));
    switch (lexical_analyser.get_token()) {
        case Token::OR:
            lexical_analyser.next_token();
            m_node->set_name("|");
            m_node->add_children(X());
            m_node->add_children(Er());
            return m_node;
        case Token::END:
            return m_node;
        default:
            return m_node;
    }
}

std::unique_ptr<Node> Parser::X() {
    std::unique_ptr<Node> m_node(new Node("X"));
    m_node->add_children(A());
    m_node->add_children(Xr());
    return m_node;
}

std::unique_ptr<Node> Parser::Xr() {
    std::unique_ptr<Node> m_node(new Node("X'"));
    switch (lexical_analyser.get_token()) {
        case Token::XOR:
            lexical_analyser.next_token();
            m_node->set_name("^");
//            m_node->add_children(A());
            m_node->add_children(Xr());
            return m_node;
        case Token::END:
            return m_node;
        default:
            return m_node;
    }
}

std::unique_ptr<Node> Parser::A() {
    std::unique_ptr<Node> m_node(new Node("A"));
    m_node->add_children(N());
    m_node->add_children(Ar());
    return m_node;
}

std::unique_ptr<Node> Parser::Ar() {
    std::unique_ptr<Node> m_node(new Node("A'"));
    switch (lexical_analyser.get_token()) {
        case Token::AND:
            lexical_analyser.next_token();
            m_node->set_name("&");
//            m_node->add_children(N());
            m_node->add_children(A());
            return m_node;
        case Token::END:
            return m_node;
        default:
            return m_node;
    }
}

std::unique_ptr<Node> Parser::N() {
    std::unique_ptr<Node> m_node(new Node("N"));
    switch (lexical_analyser.get_token()) {
        case Token::NOT:
            lexical_analyser.next_token();
            m_node->set_name("!");
            m_node->add_children(N());
            return m_node;
        case Token::END:
            return m_node;
        default:
            m_node->add_children(B());
            return m_node;
    }
}

std::unique_ptr<Node> Parser::B() {
    std::unique_ptr<Node> m_node(new Node("B"));
    size_t br_pos;
    switch (lexical_analyser.get_token()) {
        case Token::LBRACKET:
            br_pos = lexical_analyser.get_position();
            lexical_analyser.next_token();
            m_node->add_children(E());
            if (lexical_analyser.get_token() == Token::RBRACKET) {
                lexical_analyser.next_token();
                m_node->set_name("(");
                return m_node;
            } else {
                throw std::runtime_error(
                        std::string("no matching bracket for bracket at: ").append(
                                std::to_string(br_pos)));
            };
            break;
        case Token::VARIABLE:
            m_node->add_children(
                    new Node(std::string("variable=").append(std::to_string(lexical_analyser.get_char()))));
            lexical_analyser.next_token();
            return m_node;
        case Token::END:
            return m_node;
        default:
            throw std::runtime_error(
                    std::string("parsing fault at: ").append(std::to_string(lexical_analyser.get_position())));
    }
}

std::unique_ptr<Node> Parser::parse() {
    lexical_analyser.next_token();
    return E();
}

void Parser::print_tree(Node *ptr) {
    std::cout << ptr->name << std::endl;
    go_print(ptr, 1);
}

void Parser::go_print(Node *ptr, size_t depth) {
    std::string tabs;
    for (size_t i = 0; i < depth - 1; ++i) {
        tabs += "| ";
    }
    tabs += "⌞ ";
    for (auto &child : ptr->children) {
        std::cout << tabs << child->name << std::endl;
        go_print(child.get(), depth + 1);
    }
}


void LexicalAnalyser::next_token() {
    next_char();
    while (is_whilespace()) {
        next_char();
    }
    switch (cur_char) {
        case '(':
            cur_token = Token::LBRACKET;
            break;
        case ')':
            cur_token = Token::RBRACKET;
            break;
        case '!':
            cur_token = Token::NOT;
            break;
        case '|':
            cur_token = Token::OR;
            break;
        case '&':
            cur_token = Token::AND;
            break;
        case '^':
            cur_token = Token::XOR;
            break;
        case '\0':
            cur_token = Token::END;
            break;
        default:
            cur_token = Token::VARIABLE;
            break;
    }
}

void LexicalAnalyser::next_char() {
    if (cur_char = m_istream.get(); cur_char == -1) {
        cur_char = '\0';
    }
}

Token LexicalAnalyser::get_token() {
    return cur_token;
}

int LexicalAnalyser::get_position() {
    return cur_pos;
}

bool LexicalAnalyser::is_whilespace() {
    return cur_char == '\n' || cur_char == '\t' || cur_char == ' ' || cur_char == '\r';
}

char LexicalAnalyser::get_char() {
    return cur_char;
}
