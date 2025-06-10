#include <stdio.h>
#include <time.h>

#define MAX 200 // Aumentei o m�ximo para aceitar valores maiores

unsigned long long memo[MAX];

unsigned long long f(int n) {
    if (n <= 1) return 1;
    if (memo[n] != 0) return memo[n];
    memo[n] = f(n - 1) + f(n - 2);
    return memo[n];
}

int main() {
    int n;
    int NMax = 10;  // n�mero de execu��es para m�dia (pode colocar 1 para s� uma execu��o)
    double total_time = 0;
    unsigned long long resultado = 0;

    printf("Digite um valor inteiro: ");
    scanf("%d", &n);

    if (n >= MAX) {
        printf("Erro: n muito grande. Aumente o valor de MAX.\n");
        return 1;
    }

    for (int i = 0; i < NMax; i++) {
        for (int j = 0; j <= n; j++) memo[j] = 0; // limpa o memo antes de cada execu��o

        clock_t start = clock();
        resultado = f(n);
        clock_t end = clock();

        total_time += (double)(end - start) / CLOCKS_PER_SEC;
    }

    printf("f(%d) = %llu\n", n, resultado);
    printf("Tempo m�dio para f(%d) ap�s %d execu��es: %f segundos\n", n, NMax, total_time / NMax);

    return 0;
}
