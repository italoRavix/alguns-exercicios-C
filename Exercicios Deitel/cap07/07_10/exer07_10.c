// Exercicio 07_10

#include<stdio.h>

int main(void)
{
    long int value1 = 200000, value2;
    
    // a
    long int *lPtr;
    
    // b
    lPtr = &value1;
    
    // c
    printf("Valor do objeto apontado por lPtr: %ld\n", *lPtr);
    
    // d 
    value2 = *lPtr;
    
    // e
    printf("Valor de value2: %li\n", value2);
    
    // f
    printf("Endereço value1 %p\n", &value1);
    
    // g
    printf("Endereço em lPtr %p\n", lPtr);
    
    //Sim o endereço é o mesmo
    
}

