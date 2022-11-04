/*
Faça uma main interativa com comandos para ler, somar, multiplicar, imprimir e etc. matrizes esparsas. A entrada deve ser feita da seguinte forma:



é obrigatório o uso de aloca¸cão dinâamica de memoria para implementar
as listas de adjacencia que representam as matrizes.
*/


#include <iostream>
#include "SparseMatrix.h"
#include <fstream>


SparseMatrix* readSparseMatrix(std::string filename){
    std::ifstream file(filename);
    int rows, cols, value, row, col;
    file >> rows >> cols;
    SparseMatrix* matrix = new SparseMatrix(rows, cols);
    while(file >> row >> col >> value){
        matrix->insert(row, col, value);
    }
    return matrix;
}

SparseMatrix* sum(SparseMatrix* A, SparseMatrix* B){
      if (A->getRows() != B->getRows() || A->getColumns() != B->getColumns()){
            throw std::invalid_argument("Matrizes de dimensões diferentes");
        }
        SparseMatrix* aux = new SparseMatrix(A->getRows(), A->getColumns());
        for (int i = 1; i <= A->getRows(); i++){
            for (int j = 1; j <= A->getColumns(); j++){
                aux->insert(i, j, A->get(i, j) + B->get(i, j));
            }
        }
        return aux;    
    
}


SparseMatrix* multiply(SparseMatrix* A, SparseMatrix* B){
    if(A->getColumns() == B->getRows()){
        SparseMatrix* aux = new SparseMatrix(B->getColumns(), A->getRows());

        for (int i = 1; i <= aux->getRows(); i++){
            for (int j = 1; j <= aux->getColumns(); j++){
                int temp = 0;
                for (int k = 1; k <= A->getColumns(); k++){
                    temp += A->get(i, k) * B->get(k, j);
                }
                
                aux->insert(i, j, temp);
            }
        }

        return aux;
    }
}

int main(){
  
}