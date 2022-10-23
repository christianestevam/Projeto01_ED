#include <stdexcept>

#include "SparseMatrix.h"

//Construtor passando o número de linhas e colunas da matrix
SparseMatrix::SparseMatrix(int cols, int rows){
    this->m_columns = cols;
    this->m_rows = rows;

    this->m_head = new Node(0, 0, 0, nullptr, nullptr);
    Node* aux = this->m_head;

    for (int i = 1; i <= cols; i++){
        aux->next_h = new Node(0, 0, i, nullptr, nullptr);
        aux = aux->next_h;
        aux->next_h = this->m_head;
        aux->next_v = aux;
    }

    aux = this->m_head;
    for (int i = 1; i <= rows; i++){
        aux->next_v = new Node(0, i, 0, nullptr, nullptr);
        aux = aux->next_v;
        aux->next_v = this->m_head;
        aux->next_h = aux;
    }
    
}
//Destrutor
SparseMatrix::~SparseMatrix(){

}
//Inserir elemento na matrix
void SparseMatrix::insert(int i, int j, double value){

}
// i = colunas j = linhas      O(1)
double SparseMatrix::get(int i, int j){
    if(i > this->m_columns || i < 0 || j > this->m_rows || j < 0)
        throw std::range_error("index out of range");

    Node* aux = this->m_head->next_h;

    while(aux->col != i){
        aux = aux->next_h;
    }

    aux = aux->next_v;
    while (aux->row == j || aux->row == 0){
        aux = aux->next_v;
    }

    if(aux->row == 0)
        return 0;

    return aux->value;
}
//
void SparseMatrix::print(){


}