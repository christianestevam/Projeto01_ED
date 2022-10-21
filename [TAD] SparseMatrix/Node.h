#ifndef NODE_H
#define NODE_H

struct Node {
    Node* next_h;
    Node* next_v;
    int row;
    int col;
    double value;

    Node(double val, int col, int row,  Node* node_h, Node* node_v){
        this->value = val;
        this->col = col;
        this->row = row;
        this->next_h = node_h;
        this->next_v = node_v;
    }
};

#endif