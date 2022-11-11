/************************************************************ 
 * CHRISTIAN ESTAVAM BARBOSA - 538863
 * KALMAX DOS SANTOS SOUSA - 537794
*************************************************************/

#include <iostream>
#include "SparseMatrix.h"
#include <fstream>


SparseMatrix* readSparseMatrix(std::string filename){
    std::ifstream file(filename);
    int rows, cols, value, row, col;
    file >> rows >> cols;
    SparseMatrix* matrix = new SparseMatrix(rows, cols);
    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= cols; j++)
        {
            file >> value;
            matrix->insert(i, j, value);
            /* code */
        }
    }
    return matrix;
}

SparseMatrix* sum(SparseMatrix* A, SparseMatrix* B){
    if(A->getRows() == B->getRows() && A->getColumns() == B->getColumns()){
        SparseMatrix* aux = new SparseMatrix(A->getRows(), A->getColumns()); // Cria uma matriz auxiliar
        for(int i =1; i <= A->getRows(); i++){ // Percorre as linhas
            for(int j = 1; j <= A->getColumns(); j++){  // Percorre as colunas
                aux->insert(i, j, A->get(i, j) + B->get(i, j));  // Insere o valor da soma na matriz auxiliar
            }
        }
        return aux; // Retorna a matriz auxiliar
    }
}


SparseMatrix* multiply(SparseMatrix* A, SparseMatrix* B){
    if(A->getColumns() == B->getRows()){
        SparseMatrix* aux = new SparseMatrix(A->getRows(), B->getColumns());

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
   
   
    SparseMatrix* A = readSparseMatrix("A.txt");
    SparseMatrix* B = readSparseMatrix("B.txt");
    SparseMatrix* A1 = readSparseMatrix("A.txt");
    
    SparseMatrix* C = sum(A, A1);
    SparseMatrix* D = multiply(A, B);
    std::cout << "A:" << std::endl;
    A->print();
    std::cout << "B:" << std::endl;
    B->print();
    std::cout << "C:" << std::endl;
    C->print();
    std::cout << "D:" << std::endl;
    D->print();
    return 0;
   std :: cout << B ->get(1, 2) << std::endl;
   B->print();
   
}
