#include<stdio.h>
#include<stdlib.h>

typedef struct No {
    int dado;             
    struct No* esquerdo;   
    struct No* direito;   
} No;

No* criarNo(int dado) {
    No* novoNo = (No*) malloc(sizeof(No));
    novoNo->dado = dado;
    novoNo->esquerdo = NULL;
    novoNo->direito = NULL;
    return novoNo;
}

int main() {
    No* raiz = criarNo(1);
    raiz->esquerdo = criarNo(2);
    raiz->direito = criarNo(3);
    raiz->esquerdo->esquerdo = criarNo(4);

    return 0;
}
