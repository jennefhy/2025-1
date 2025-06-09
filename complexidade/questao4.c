#include <stdio.h>
#include <time.h>

int f(int n) {
    if (n <= 1) return 1;
    return f(n - 1) + f(n - 2);
}

int main() {
    int n;
    int NMax = 1000;
    double total_time = 0;

    printf("Digite um valor inteiro: ");
    scanf("%d", &n);

    int resultado = 0;

    for (int i = 0; i < NMax; i++) {
        clock_t start = clock();
        resultado = f(n);
        clock_t end = clock();
        total_time += (double)(end - start) / CLOCKS_PER_SEC;
    }

    printf("f(%d) = %d\n", n, resultado);
    printf("Tempo médio para f(%d) após %d execuções: %f segundos\n", n, NMax, total_time / NMax);

    return 0;
}