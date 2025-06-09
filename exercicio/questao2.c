#include<locale.h>
#include<stdio.h>

int potencia(int base, int expoente){
    if (expoente < 0)
    {
        printf("Erro!");
        return -1;
    }

    int resul = 1;
    for (int i = 0; i < expoente; i++)
    {
        resul *= base;
    }
    return resul;   
}

int main(){
    setlocale(LC_ALL, "Portuguese");

    int base, expoente;

    printf("Digite a base: ");
    scanf("%d", &base);
    printf("Digite o expoente positivo: ");
    scanf("%d", &expoente);

    int resul = potencia(base, expoente);

    if (resul != -1)
    {
        printf("%d elevado a %d = %d\n", base, expoente, resul);
    }
    return 0;
}