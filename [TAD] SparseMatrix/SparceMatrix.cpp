/************************************************************ 
 * CHRISTIAN ESTAVAM BARBOSA - 538863
 * KALMAX DOS SANTOS SOUSA - 537794
*************************************************************/

#include <iostream>
#include <stdexcept>
#include "SparseMatrix.h"

SparseMatrix::SparseMatrix(int rows, int cols){
    this->m_rows = rows;
    this->m_columns = cols;

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
// Completexidade O(n^2)
SparseMatrix::~SparseMatrix(){
 
    Node* aux = this->m_head->next_h;

    while(aux != this->m_head){
        Node* aux2 = aux->next_v;
        while(aux2 != aux){
            Node* temp = aux2->next_v;
            delete aux2;
            aux2 = temp;
        }

        
        Node* temp = aux->next_h;
        delete aux;
        aux = temp;
    }

    aux = this->m_head->next_v;
    while(aux != this->m_head){
        Node* temp = aux->next_v;
        delete aux;
        aux = temp;
    }

    delete this->m_head;
}

//Inserir elemento na matrix
//Inserir elemento na matrix
// Complexidade: O(n)
void SparseMatrix::insert(int i, int j, double value){
    if (i > this->m_rows || j > this->m_columns || i < 1 || j < 1){    // verifica se a posição é válida
        throw std::out_of_range("Posição inválida");
    }

    Node* aux1 = this->m_head->next_v;
    Node* aux2 = this->m_head->next_h;

    while (aux1->row != i){
        aux1 = aux1->next_v;
    }

    while (aux2->col != j){
        aux2 = aux2->next_h;
    }

    while (aux1->next_h->col < j && aux1->next_h->col != 0){
        aux1 = aux1->next_h;
    }

    while (aux2->next_v->row < i && aux2->next_v->row != 0){
        aux2 = aux2->next_v;
    }

    if (aux1->next_h->col == i && aux2->next_v->row == j){   
        aux1->next_h->value = value;
    } else {
        Node* novo = new Node(value, i, j, aux1->next_h, aux2->next_v);
        aux1->next_h = novo;
        aux2->next_v = novo;
    }
     
}

double SparseMatrix::get(int i, int j){ // i = linhas j = colunas      O(1)
    //Varifica se os índices são válidos e são n, retorna uma excessão
    if(i > this->m_rows || i < 0 || j > this->m_columns || j < 0)
        throw std::range_error("index out of range");

    //auxiliar para percorrer as colunas
    Node* aux = this->m_head->next_h;

    //percorre até o aux chegar na coluna desejada
    while(aux->col != j){
        aux = aux->next_h;
    }

    //sai do nó cabeça da coluna para a próxima linha, caso haja
    aux = aux->next_v;

    //percorre as linhas até encontrar um nó que se  encontra na mesma linha do parâmetro ou até o primeiro nó, caso não encontre
    while (aux->row != i && aux->row != 0){
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

int SparseMatrix::getColumns(){
    return this->m_columns;
}

int SparseMatrix::getRows(){
    return this->m_rows;
}