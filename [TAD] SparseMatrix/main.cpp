/************************************************************ 
 * CHRISTIAN ESTAVAM BARBOSA - 538863
 * KALMAX DOS SANTOS SOUSA - 537794
*************************************************************/

#include <iostream>
#include "SparseMatrix.h"
#include <fstream>


SparseMatrix* readSparseMatrix(std::string filename){  //O(n)
    std::ifstream file(filename);
    int rows, cols, row, col;
    double value;

    file >> rows >> cols;
    SparseMatrix* matrix = new SparseMatrix(rows, cols);
    while(file >> row >> col >> value){
            matrix->insert(row, col, value);
    }

    return matrix;
}

SparseMatrix* sum(SparseMatrix* A, SparseMatrix* B){ //O(n²)
        if(A->getRows() == B->getRows() && A->getColumns() == B->getColumns()){
            SparseMatrix* aux = new SparseMatrix(A->getRows(), A->getColumns()); // Cria uma matriz auxiliar
            for(int i =1; i <= A->getRows(); i++){ // Percorre as linhas
                for(int j = 1; j <= A->getColumns(); j++){  // Percorre as colunas
                    aux->insert(i, j, A->get(i, j) + B->get(i, j));  // Insere o valor da soma na matriz auxiliar
                }
            }
            return aux; // Retorna a matriz auxiliar
        }
        else{
            throw std::runtime_error("As matrizes não podem ser somadas");
        }
}


SparseMatrix* multiply(SparseMatrix* A, SparseMatrix* B){ //O(n³)
    if(A->getColumns() == B->getRows()){
        SparseMatrix* aux = new SparseMatrix(A->getRows(), B->getColumns());

        for (int i = 1; i <= aux->getRows(); i++){
            for (int j = 1; j <= aux->getColumns(); j++){
                double temp = 0;
                for (int k = 1; k <= A->getColumns(); k++){
                    temp += A->get(i, k) * B->get(k, j);
                }       
                aux->insert(i, j, temp);
            }
        }
        return aux;
    }

    else{
        throw std::runtime_error("As matrizes não podem ser multiplicadas");
    }
}


int main(){
    SparseMatrix* A = readSparseMatrix("A.txt");
    std::cout << "A:" << std::endl;
    A->print();


    SparseMatrix* B = readSparseMatrix("B.txt");
    std::cout << "B:" << std::endl;
    B->print();

    SparseMatrix* C;
    try{
        C = sum(A, B);
        std::cout << "C:" << std::endl;
        C->print();

    }catch(const std::runtime_error ex){
        std::cout << ex.what() << std::endl;
    }

    SparseMatrix* D;
    try{
        D = multiply(A, B);
        std::cout << "D:" << std::endl;
        D->print();

    }catch(const std::runtime_error ex){
        std::cout << ex.what() << std::endl;
    }

    delete A;
    delete B;
    delete C;
    delete D;
    return 0;
}
