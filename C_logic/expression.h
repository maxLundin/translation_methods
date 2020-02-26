//
// Created by max on 14.04.19.
//

#pragma once

#include <memory>
#include <string>
#include <vector>

class Node {
    std::vector<std::unique_ptr<Node>> children;
    std::string name;

public:
    Node(std::string st) : name(std::move(st)) {}

    void set_name(std::string new_name) {
        name = std::move(new_name);
    }

    void add_children(Node *);

    void add_children(std::unique_ptr<Node> &&);

    friend class Parser;
};

inline void Node::add_children(Node *child) {
    children.emplace_back(child);
}

inline void Node::add_children(std::unique_ptr<Node> &&up) {
    children.emplace_back(std::move(up));
}
