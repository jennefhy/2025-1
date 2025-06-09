#include<locale.h>
#include<stdio.h>

int f(int n){
    if (n <= 1)
        return 1;
else 
    return f(n-1) + f(n-2);
}

int main(){
    setlocale(LC_ALL, "Portuguese");

    int n;
    printf("Digite o valor de n: ")
    scanf("%d", &n);
    printf("x(%d) = %d\n", n, f);
    return 0;
}