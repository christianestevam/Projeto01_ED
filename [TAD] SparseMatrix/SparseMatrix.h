#ifndef SPARSEMATRIX_H
#define SPARSEMATRIX_H

#include "Node.h"

class SparseMatrix{
    private: 
        Node* m_head {nullptr};
        int m_columns {0};
        int m_rows {0};

    public:
        //Construtor passando o número de linhas e colunas da matrix
        SparseMatrix(int cols, int rows);
        //Destrutor
        ~SparseMatrix();
        //Inserir elemento na matrix
        void insert(int i, int j, double value);
        //
        double get(int i, int j);
        //
        void print();

        int getColumns();

        int getRows();
};

#endif