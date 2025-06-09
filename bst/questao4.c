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

No* buscar(No* T, int c) {
    if (T == NULL)
        return NULL;
    if (T->dado == c)
        return T;
    if (c < T->dado)
        return buscar(T->esquerdo, c);
    else
        return buscar(T->direito, c);
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    No* raiz = criarNo(10);
    raiz->esquerdo = criarNo(5);
    raiz->direito = criarNo(15);

    int chave = 5;
    No* resul = buscar(raiz, chave);
    if (resul != NULL)
        printf("Nó com dado %d encontrado.\n", resul->dado);
    else
        printf("Nó com dado %d não encontrado.\n", chave);

    return 0;
}