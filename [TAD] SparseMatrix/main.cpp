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
    SparseMatrix* aux = new SparseMatrix(A->getRows(), A->getColumns()); // Cria uma matriz auxiliar
    for(int i = 0; i < A->getRows(); i++){ // Percorre as linhas
        for(int j = 0; j < A->getColumns(); j++){  // Percorre as colunas
            aux->insert(i, j, A->get(i, j) + B->get(i, j));  // Insere o valor da soma na matriz auxiliar
        }
    }
    return aux; // Retorna a matriz auxiliar
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
