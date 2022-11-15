/************************************************************ 
 * CHRISTIAN ESTAVAM BARBOSA - 538863
 * KALMAX DOS SANTOS SOUSA - 537794
*************************************************************/

#include <iostream>
#include <stdexcept>
#include "SparseMatrix.h"

SparseMatrix::SparseMatrix(int rows, int cols){ // O(n)
    this->m_rows = rows;
    this->m_columns = cols;

    this->m_head = new Node(0, 0, 0, nullptr, nullptr);
    Node* aux = this->m_head;

    for (int i = 1; i <= cols; i++){
        aux->next_x = new Node(0, 0, i, nullptr, nullptr);
        aux = aux->next_x;
        aux->next_x = this->m_head;
        aux->next_y = aux;
    }

    aux = this->m_head;
    for (int i = 1; i <= rows; i++){
        aux->next_y = new Node(0, i, 0, nullptr, nullptr);
        aux = aux->next_y;
        aux->next_y = this->m_head;
        aux->next_x = aux;
    }   
}

SparseMatrix::~SparseMatrix(){ // O(n²)
    Node* aux = this->m_head->next_x;

    while(aux != this->m_head){
        Node* aux2 = aux->next_y;

        while(aux2 != aux){
            Node* temp = aux2->next_y;
            delete aux2;
            aux2 = temp;
        }

        Node* temp = aux->next_x;
        delete aux;
        aux = temp;
    }

    aux = this->m_head->next_y;
    while(aux != this->m_head){
        Node* temp = aux->next_y;
        delete aux;
        aux = temp;
    }

    delete this->m_head;
}

void SparseMatrix::insert(int i, int j, double value){ // O(n)
    if (i > this->m_rows || j > this->m_columns || i < 1 || j < 1){
        throw std::out_of_range("Posição inválida");
    }

    Node* aux1 = this->m_head->next_y;
    Node* aux2 = this->m_head->next_x;

    while (aux1->row != i)
        aux1 = aux1->next_y;

    while (aux2->col != j)
        aux2 = aux2->next_x;

    while (aux1->next_x->col < j && aux1->next_x->col != 0)
        aux1 = aux1->next_x;

    while (aux2->next_y->row < i && aux2->next_y->row != 0)
        aux2 = aux2->next_y;

    if (aux1->next_x->col == i && aux2->next_y->row == j){   
        if(value == 0){
            Node* temp1 = aux1->next_x->next_x;
            Node* temp2 = aux1->next_x->next_y;
            delete aux1->next_x;
            aux1->next_x = temp1;
            aux2->next_y = temp2;
        }
        else{
            aux1->next_x->value = value;
        }
    } else {
        Node* novo = new Node(value, i, j, aux1->next_x, aux2->next_y);
        aux1->next_x = novo;
        aux2->next_y = novo;
    }
     
}

double SparseMatrix::get(int i, int j){ // O(n)
    if(i > this->m_rows || i < 0 || j > this->m_columns || j < 0)
        throw std::range_error("index out of range");

    Node* aux = this->m_head->next_x;

    while(aux->col != j)
        aux = aux->next_x;

    aux = aux->next_y;

    while (aux->row != i && aux->row != 0)
        aux = aux->next_y;

    if(aux->row == 0) 
        return 0;

    return aux->value;
}
//
void SparseMatrix::print(){ //O(n²)    
    Node* aux = this->m_head->next_y;

    while(aux != this->m_head){
        Node* temp = aux->next_x;

        for (int i = 1; i <= this->m_columns; i++){
            if(i != 1)
                std::cout << " ";

            if(temp->col == i){
                std::cout << temp->value;
                temp = temp->next_x;

            } else
                std::cout << 0;
        }

        std::cout<< std::endl;
        aux = aux->next_y;
    }
}

int SparseMatrix::getColumns(){ // O(1)
    return this->m_columns;
}

int SparseMatrix::getRows(){ // O(1)
    return this->m_rows;
}