// Exercicio 13_05
// Este programa faz a soma de dois numeros usando uma macro

#include <stdio.h>

#define SUM(x,y) (x + y)

int main(void)
{
    int x = 3, y = 8;
    
    printf("%d + %d = %d\n", x, y, SUM(x,y));
    return 0;
}
