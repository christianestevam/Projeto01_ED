/************************************************************ 
 * CHRISTIAN ESTAVAM BARBOSA - 538863
 * KALMAX DOS SANTOS SOUSA - 537794
*************************************************************/

#ifndef SPARSEMATRIX_H
#define SPARSEMATRIX_H

#include "Node.h"

class SparseMatrix{
    private: 
        Node* m_head {nullptr};
        int m_columns {0};
        int m_rows {0};

    public:
        // Construtor passando o número de linhas e colunas da matriz
        SparseMatrix(int cols, int rows);

        // Destrutor
        ~SparseMatrix();

        // Inserir/Substituir elemento na matrix passando número de linhas e colunas e o valor a ser inserido
        void insert(int i, int j, double value);

        // Retornar elemento da matriz
        double get(int i, int j);

        // Imprimir a matriz
        void print();

        //Retornar o número de colunas da matriz
        int getColumns();

        //Retornar o número de linhas da matriz
        int getRows();
};

#endif