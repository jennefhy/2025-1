#include<locale.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct No {
    int dado;
    struct No* esquerdo;
    struct No* direito;
} No;

void remover(No* T) {
    if (T != NULL) {
        remover(T->esquerdo);
        remover(T->direito);
        free(T);
    }
}

No* criarNo(int dado) {
    No* novoNo = (No*) malloc(sizeof(No));
    if (novoNo != NULL) {
        novoNo->dado = dado;
        novoNo->esquerdo = NULL;
        novoNo->direito = NULL;
    }
    return novoNo;
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    No* raiz = criarNo(1);
    raiz->esquerdo = criarNo(2);
    raiz->direito = criarNo(3);

    remover(raiz);
    raiz = NULL;

    printf("Árvore removida e memória liberada.\n");
    return 0;
}