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

