// Exercicio 13_10
// Este programa define uma macro para somar valores inteiros em um array

#include <stdio.h>
#define SUMARRAY(array, length) \
    int i = 0, sum = 0; \
    for(i; i < length; i++) \
        sum += array[i]; \
    printf("Sum: %d\n", sum)

int main (void)
{
    int a[] = {3, 0, 0, 0, 7, 0}, b = sizeof(a) / sizeof(a[0]);
    
    SUMARRAY(a, b);
    return 0;
}

