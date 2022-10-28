#ifndef NODE_H
#define NODE_H

#include <iostream>

struct Node {
    Node* next_h;
    Node* next_v;
    int row;
    int col;
    double value;

    Node(double val, int row, int col,  Node* node_h, Node* node_v){
        this->value = val;
        this->col = col;
        this->row = row;
        this->next_h = node_h;
        this->next_v = node_v;
    }

    ~Node(){
        std::cout << "No " << this->value << " (" <<this->row << ", " << this->col  << ") destruido" << std::endl;
    }
};

#endif