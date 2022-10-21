#ifndef NODE_H
#define NODE_H

struct Node {
    Node* next_h;
    Node* next_v;
    int row;
    int col;
    double value;
};

#endif