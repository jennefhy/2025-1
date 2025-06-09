#include <stdio.h>

int f(int n) {
    if (n <= 1)
        return 1;
    else
        return f(n - 1) + f(n - 2);
}

int main() {
    int n;
    printf("Digite um valor inteiro: ");
    scanf("%d", &n);
    printf("f(%d) = %d\n", n, f(n));
    return 0;
}
