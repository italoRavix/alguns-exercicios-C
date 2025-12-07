// Exercicio 07_09

#include<stdio.h>

#define SIZE 5 // constante simbolica para o tamanho do array

int main(void)
{
    // a
    unsigned int values[SIZE] = {2, 4, 6, 8, 10};
    
    // b 
    unsigned int *vPtr;
    
    // c
    printf("\nLetra C\n");
    for(int i = 0; i <  SIZE; i++)
        printf("%d: %d\n", i, values[i]);
        
    // d
    vPtr = values;     // como um nome de array é nada mais nada menos que um ponteiro para
    vPtr = &values[0]; // o primeiro valor do array, ambas as instruçoes sao equivalentes
    
    // e 
    printf("\nLetra E\n");
    for(int i = 0; i <  SIZE; i++)
        printf("%d: %d\n", i, *(vPtr + i));
        
   // f 
    printf("\nLetra F\n");
    for(int i = 0; i <  SIZE; i++)
        printf("%d: %d\n", i, *(values + i));
        
    // g
    printf("\nLetra G\n");    
    for(int i = 0; i <  SIZE; i++)
        printf("%d: %d\n", i, vPtr[i]);
        
    // h
    printf("Subscrito de array: %d\n", values[4]);
    printf("Ponteiro/Deslocamento com nome do array: %d\n", *(values + 4));    
    printf("Subscrito de ponteiro: %d\n", vPtr[4]);    
    printf("Ponteiro/Deslocamento com ponteiro: %d\n", *(vPtr + 4));    
    
    // i 
    // endereço de memoria inicial + indice desejado * tamanho do dado = endereço referenciado
    // 1002500 + 3 * 16 = 1002548
    // valor: 8
    
    // j
    // 1002500 + 4 * 16 = 1002564 = endereço de values[4]
    // 1002564 - 4 * 16 = 1002500
    // valor: 2
    
}
