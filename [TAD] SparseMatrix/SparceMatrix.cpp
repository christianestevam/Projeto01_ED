#include <iostream>
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
/*
//Destrutor
// Completexidade O(n^2)
SparseMatrix::~SparseMatrix(){
    // Node criado para percorrer a matriz
    Node* aux = this->m_head;
    // Node criado para apagar os nós
    Node* aux2 = this->m_head;
   // Percorre a matriz 
    while (aux->next_h != this->m_head){
        aux = aux->next_h;
        // Percorre a linha da matriz e apaga os nós preenchidos com valor diferente de 0
        while (aux->next_v != aux){
            aux2 = aux->next_v;
            aux->next_v = aux2->next_v;
            delete aux2;
        }
        // Apaga o nó cabeça da linha da matriz
        aux2 = aux;
        aux = aux->next_h;
        delete aux2;
    }
    // Enquanto o nó cabeça da coluna não for o nó cabeça da matriz apaga o nó cabeça da coluna da matriz
    while (aux->next_v != aux){
        aux2 = aux->next_v;
        aux->next_v = aux2->next_v;
        delete aux2;
    }
    delete aux;
}
*/
//Inserir elemento na matrix
//Inserir elemento na matrix
// Complexidade: O(n)
void SparseMatrix::insert(int i, int j, double value){
    if (i > this->m_rows || j > this->m_columns || i < 1 || j < 1){    // verifica se a posição é válida
        throw std::out_of_range("Posição inválida");
    }

    Node* aux = this->m_head;    // auxiliar para percorrer a lista
    Node* aux2 = aux->next_h;    // auxiliar para percorrer a lista
    Node* aux3 = aux->next_v;    // auxiliar para percorrer a lista

    while (aux2->row != j){      // percorre a lista horizontal
        aux2 = aux2->next_h;     // auxiliar recebe o valor do próximo nó
    }

    while (aux3->col != i){      // percorre a lista vertical
        aux3 = aux3->next_v;     // auxiliar recebe o valor do próximo nó
    }

    while (aux2->next_h->col < i){   // percorre a lista horizontal
        aux2 = aux2->next_h;          // auxiliar recebe o valor do próximo nó
    }

    while (aux3->next_v->row < j){   // percorre a lista vertical
        aux3 = aux3->next_v;          // auxiliar recebe o valor do próximo nó
    }

    if (aux2->next_h->col == i && aux3->next_v->row == j){   // se o nó já existir
        aux2->next_h->value = value;                         // altera o valor do nó
    } else {                                                 // se o nó não existir
        Node* novo = new Node(value, i, j, aux2->next_h, aux3->next_v);   // cria um novo nó
        aux2->next_h = novo;                                             // insere o novo nó na lista horizontal
        aux3->next_v = novo;                                             // insere o novo nó na lista vertical
    }
     
}

double SparseMatrix::get(int i, int j){ // i = colunas j = linhas      O(1)
    //Varifica se os índices são válidos e são n, retorna uma excessão
    if(i > this->m_columns || i < 0 || j > this->m_rows || j < 0)
        throw std::range_error("index out of range");

    //auxiliar para percorrer as colunas
    Node* aux = this->m_head->next_h;

    //percorre até o aux chegar na coluna desejada
    while(aux->col != i){
        aux = aux->next_h;
    }

    //sai do nó cabeça da coluna para a próxima linha, caso haja
    aux = aux->next_v;

    //percorre as linhas até encontrar um nó que se  encontra na mesma linha do parâmetro ou até o primeiro nó, caso não encontre
    while (aux->row == j || aux->row == 0){
        aux = aux->next_v;
    }

    //Verifica se ele se encontra no nó cabeça;
    if(aux->row == 0)
        //Se isso acontecer, foi porque o nó não foi encontrado, portanto, ele é 0;
        return 0;

    //retorna o valor do nó encontrado
    return aux->value;
}
//
void SparseMatrix::print(){ //O(n²)
    //Cria um nó auxiliar para percorrer  a matriz
    Node* aux = this->m_head->next_v;

    //Percorre as linhas até o auxiliar se diferente do nó cabeça (0, 0)
    while(aux != this->m_head){
        //cria  um nó temporário para percorrer as colunas dentro das linhas
        Node* temp = aux->next_h;

        //um for para percorrer todda a linha;
        for (int i = 1; i <= this->m_columns; i++){
            //se for o primeiro nó, não coloca o espaço antes
            if(i != 1)
                std::cout << " ";

            //vwifica  se aquele nó pertence a coluna atual do for, se sim, imprime o valor dele  e passa para o próximmo nó
            if(temp->col == i){
                std::cout << temp->value;
                temp = temp->next_h;
            }
            //caso não encontre um nó naquela  posição, imprime 0
            else{
                std::cout << 0;
            }
        }

        std::cout<< std::endl;

        aux = aux->next_v;
    }
}