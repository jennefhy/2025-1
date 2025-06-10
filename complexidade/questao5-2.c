#include <stdio.h>
#include <time.h>

unsigned long long f_iterativo(int n) {
    if (n <= 1) return 1;
    unsigned long long a = 1, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    int n;
    int NMax = 1000;
    double total_time = 0;

    printf("Digite um valor inteiro: ");
    scanf("%d", &n);

    unsigned long long resultado = 0;

    for (int i = 0; i < NMax; i++) {
        clock_t start = clock();
        resultado = f_iterativo(n);
        clock_t end = clock();
        total_time += (double)(end - start) / CLOCKS_PER_SEC;
    }

    printf("f(%d) = %llu\n", n, resultado);
    printf("Tempo médio para f(%d) após %d execuções: %f segundos\n", n, NMax, total_time / NMax);

    return 0;
}
