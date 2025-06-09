#include<locale.h>
#include<stdio.h>

int f(int n){
    if (n <= 1)
        return 1;
else 
    return f(n-1) + f(n-2);
}