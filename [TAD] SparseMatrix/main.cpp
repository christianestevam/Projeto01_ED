#include <iostream>
#include "SparseMatrix.h"

/*
SparseMatrix* sum(SparseMatrix* A, SparseMatrix* B){
    
}

SparseMatrix* multiply(SparseMatrix* A, SparseMatrix* B){

}
*/

int main(){
    int rows = 5;
    int columns = 7;

    SparseMatrix matrix(rows, columns);

    int aux = 0;
    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= columns; j++)
        {
            aux++;
            matrix.insert(i, j, aux);
        }
        
    }

    std::cout << matrix.get(2, 1) << std::endl;

    matrix.print();
}