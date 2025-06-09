#include<locale.h>
#include<stdio.h>
#include<stdbool.h>

bool primo(int n){
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