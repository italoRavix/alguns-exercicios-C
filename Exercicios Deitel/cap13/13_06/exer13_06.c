// Exercicio 13_06
// Este programa faz a comparaçao do menor entre dois numeros usando uma macro

#include <stdio.h>

#define MINIMUN2(x,y) (x) < (y) ? x : y

int main(void)
{
    int x, y;
    
    printf("Insira dois inteiros diferentes: ");
    scanf("%d %d", &x, &y);
    
    printf("O menor deles é: %d\n", MINIMUN2(x, y));

    return 0;
}
