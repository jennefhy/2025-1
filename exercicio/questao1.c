#include<locale.h>
#include<stdio.h>
#include<stdbool.h>

bool ehPrimo(int n){
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    
    for (int i = 3; i * 1 <= n; i+=2)
    {
        if (n % i == 0)
        return false;
    }
    return true;
}

int main(){
    int num1, num2;

    printf("Digite um número inicial para o intervalo: ");
    scanf("%d", &num1);
    printf("Digite um número final para o intervalo: ");
    scanf("%d", &num2);

    if (num1 > num2){
        int temp = num1;
        num1 = num2;
        num2 = temp;
    }

    printf("Números primos entre %d e %d:\n", num1, num2);

    for (int i = num1; i <= num2; i++){
        if (ehPrimo(i))
        {
            printf("%d", i);
        }
    }
    printf("\n");
    
    return 0;
}