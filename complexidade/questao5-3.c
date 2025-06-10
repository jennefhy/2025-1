#include <stdio.h>
#include <time.h>
#include <math.h>

unsigned long long fib_binet(int n) {
    double sqrt5 = sqrt(5);
    double phi = (1 + sqrt5) / 2;
    double psi = (1 - sqrt5) / 2;

    double result = (pow(phi, n) - pow(psi, n)) / sqrt5;

    return (unsigned long long)(result + 0.5); // arredondar
}

int main() {
    int n;
    int NMax = 1000;
    double total_time = 0;
    unsigned long long resultado;

    printf("Digite um valor inteiro (max 93): ");
    scanf("%d", &n);

    if (n > 93) {
        printf("Erro: n muito grande para unsigned long long.\n");
        return 1;
    }

    for (int i = 0; i < NMax; i++) {
        clock_t start = clock();
        resultado = fib_binet(n);
        clock_t end = clock();
        total_time += (double)(end - start) / CLOCKS_PER_SEC;
    }

    printf("f(%d) = %llu\n", n, resultado);
    printf("Tempo médio para f(%d) após %d execuções: %f segundos\n", n, NMax, total_time / NMax);

    return 0;
}
