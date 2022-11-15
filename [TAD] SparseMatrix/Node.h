/************************************************************ 
 * CHRISTIAN ESTAVAM BARBOSA - 538863
 * KALMAX DOS SANTOS SOUSA - 537794
*************************************************************/

#ifndef NODE_H
#define NODE_H

#include <iostream>

struct Node {
    Node* next_x;
    Node* next_y;
    int row;
    int col;
    double value;

    Node(double val, int row, int col,  Node* node_h, Node* node_v){
        this->value = val;
        this->col = col;
        this->row = row;
        this->next_x = node_h;
        this->next_y = node_v;
    }
};

#endif