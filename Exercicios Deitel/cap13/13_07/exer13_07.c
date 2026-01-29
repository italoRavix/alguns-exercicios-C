// Exercicio 13_07
// Este programa faz a comparaçao do menor entre tres numeros usando uma macro

#include <stdio.h>

#define MINIMUN2(x,y) (x) < (y) ? x : y
#define MINIMUN3(x, y, z) (MINIMUN2(x, y)) < (z) ? MINIMUN2(x, y) : z

int main(void)
{
    int x, y, z;
    
    printf("Insira tres inteiros diferentes: ");
    scanf("%d %d %d", &x, &y, &z);
    
    printf("O menor deles é: %d\n", MINIMUN3(x, y, z));

    return 0;
}
