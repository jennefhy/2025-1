#include<locale.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct No {
    int dado;
    struct No* esquerdo;
    struct No* direito;
} No;

No* criarNo(int c) {
    No* novoNo = (No*) malloc(sizeof(No));
    if (novoNo != NULL) {
        novoNo->dado = c;
        novoNo->esquerdo = NULL;
        novoNo->direito = NULL;
    }
    return novoNo;
}

No* inserir(No* T, int c) {
    if (T == NULL)
        return criarNo(c);
    if (c < T->dado)
        T->esquerdo = inserir(T->esquerdo, c);
    else if (c > T->dado)
        T->direito = inserir(T->direito, c);
    return T;
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    No* raiz = NULL;
    raiz = inserir(raiz, 10);
    raiz = inserir(raiz, 5);
    raiz = inserir(raiz, 15);

    printf("Nós inseridos na árvore binária.\n");
    return 0;
}
