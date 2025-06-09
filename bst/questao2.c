#include<stdio.h>
#include<stdlib.h>

typedef struct No {
    int dado;
    struct No* esquerdo;
    struct No* direito;
} No;

No* criarNo(int c) {
    No* T = (No*) malloc(sizeof(No));
    if (T != NULL) {
        T->esquerdo = NULL;
        T->direito = NULL;
        T->dado = c;
    }
    return T;
}

int main() {
    No* raiz = criarNo(10);
    if (raiz != NULL) {
        printf("No criado com dado: %d\n", raiz->dado);
    } else {
        printf("Falha na alocacao de memoria.\n");
    }
    return 0;
}

//O algoritmo cria um novo n� para uma �rvore bin�ria, reservando mem�ria, inicializando os ponteiros dos filhos como NULL, 
//armazenando a chave c no n� e retornando o ponteiro para esse n�. Esse n� pode ser usado como raiz ou filho para construir a �rvore.