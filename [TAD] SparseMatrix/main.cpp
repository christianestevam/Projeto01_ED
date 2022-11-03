#include <iostream>
#include "SparseMatrix.h"

/*
SparseMatrix* sum(SparseMatrix* A, SparseMatrix* B){
    
}
*/

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
    int rows = 3;
    int columns = 5;

    SparseMatrix matrix1(rows, columns);
    SparseMatrix matrix2(columns, rows);

    int aux = 0;
    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= columns; j++)
        {
            aux++;
            matrix1.insert(i, j, aux);
        }
    }
        

    for (int i = 1; i <= columns; i++)
    {
        for (int j = 1; j <= rows; j++)
        {
            aux++;
            matrix2.insert(i, j, aux);
        }
        
    }

    matrix1.print();
    std::cout << std::endl;
    matrix2.print();
    std::cout << std::endl;

    SparseMatrix* result = multiply(&matrix1, &matrix2);
    result->print();
}