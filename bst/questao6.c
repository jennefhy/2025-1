#include<locale.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct No {
    int dado;
    struct No* esquerdo;
    struct No* direito;
} No;

//Criar nó
No* criarNo(int c) {
    No* novoNo = (No*) malloc(sizeof(No));
    if (novoNo != NULL) {
        novoNo->dado = c;
        novoNo->esquerdo = NULL;
        novoNo->direito = NULL;
    }
    return novoNo;
}

//Inserir
No* inserir(No* T, int c) {
    if (T == NULL)
        return criarNo(c);
    if (c < T->dado)
        T->esquerdo = inserir(T->esquerdo, c);
    else if (c > T->dado)
        T->direito = inserir(T->direito, c);
    return T;
}

//Buscar
No* buscar(No* T, int c) {
    if (T == NULL || T->dado == c)
        return T;
    if (c < T->dado)
        return buscar(T->esquerdo, c);
    else
        return buscar(T->direito, c);
}

//Remover toda árvore (liberar memória)
void remover(No* T) {
    if (T != NULL) {
        remover(T->esquerdo);
        remover(T->direito);
        free(T);
    }
}

//Percurso em ordem
void emOrdem(No* T) {
    if (T == NULL) return;
    emOrdem(T->esquerdo);
    printf("%d ", T->dado);
    emOrdem(T->direito);
}

//Percurso pré-ordem
void preOrdem(No* T) {
    if (T == NULL) return;
    printf("%d ", T->dado);
    preOrdem(T->esquerdo);
    preOrdem(T->direito);
}

//Percurso pós-ordem
void posOrdem(No* T) {
    if (T == NULL) return;
    posOrdem(T->esquerdo);
    posOrdem(T->direito);
    printf("%d ", T->dado);
}

//Altura da árvore
int altura(No* T) {
    if (T == NULL) return 0;
    int alturaesq = altura(T->esquerdo);
    int alturadir = altura(T->direito);
    if (alturaesq > alturadir)
        return alturaesq + 1;
    else
        return alturadir + 1;
}

//Profundidade de um nó (distância da raiz até o nó)
int profundidade(No* T, int c, int nivel) {
    if (T == NULL) return -1;
    if (T->dado == c) return nivel;
    int esquerda = profundidade(T->esquerdo, c, nivel + 1);
    if (esquerda != -1) return esquerda;
    return profundidade(T->direito, c, nivel + 1);
}

//Soma dos valores da árvore
int somaValores(No* T) {
    if (T == NULL) return 0;
    return T->dado + somaValores(T->esquerdo) + somaValores(T->direito);
}

//Nível de um nó (igual à profundidade)
int nivel(No* T, int c) {
    return profundidade(T, c, 0);
}

//Número de nós na árvore
int contarNos(No* T) {
    if (T == NULL) return 0;
    return 1 + contarNos(T->esquerdo) + contarNos(T->direito);
}

//Número de folhas na árvore
int contarFolhas(No* T) {
    if (T == NULL) return 0;
    if (T->esquerdo == NULL && T->direito == NULL) return 1;
    return contarFolhas(T->esquerdo) + contarFolhas(T->direito);
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    No* raiz = NULL;
    raiz = inserir(raiz, 10);
    raiz = inserir(raiz, 5);
    raiz = inserir(raiz, 15);
    raiz = inserir(raiz, 3);
    raiz = inserir(raiz, 7);
    raiz = inserir(raiz, 12);
    raiz = inserir(raiz, 18);

    printf("Percurso em ordem: ");
    emOrdem(raiz);
    printf("\n");

    printf("Percurso pré-ordem: ");
    preOrdem(raiz);
    printf("\n");

    printf("Percurso pós-ordem: ");
    posOrdem(raiz);
    printf("\n");

    int h = altura(raiz);
    printf("Altura da árvore: %d\n", h);

    int p = profundidade(raiz, 7, 0);
    printf("Profundidade do no 7: %d\n", p);

    int s = somaValores(raiz);
    printf("Soma dos valores: %d\n", s);

    int n = nivel(raiz, 12);
    printf("Nível do no 12: %d\n", n);

    int totalNos = contarNos(raiz);
    printf("Número total de nós: %d\n", totalNos);

    int folhas = contarFolhas(raiz);
    printf("Número de folhas: %d\n", folhas);

    remover(raiz);
    raiz = NULL;

    return 0;
}