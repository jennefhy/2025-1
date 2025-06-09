#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Aluno {
    char nome[50];
    int matricula;
    float nota;
    struct Aluno* esquerdo;
    struct Aluno* direito;
} Aluno;

Aluno* buscarNome(Aluno* raiz, const char* nome) {
    if (raiz == NULL)
        return NULL;
    int resul = strcmp(nome, raiz->nome);
    if (resul == 0)
        return raiz;
    else if (resul < 0)
        return buscarNome(raiz->esquerdo, nome);
    else
        return buscarNome(raiz->direito, nome);
}

void somaNotasEContar(Aluno* raiz, float* soma, int* contador) {
    if (raiz == NULL) return;
    somaNotasEContar(raiz->esquerdo, soma, contador);
    *soma += raiz->nota;
    (*contador)++;
    somaNotasEContar(raiz->direito, soma, contador);
}

float mediaNotas(Aluno* raiz) {
    float soma = 0.0;
    int contador = 0;
    somaNotasEContar(raiz, &soma, &contador);
    if (contador == 0)
        return 0.0;
    return soma / contador;
}
