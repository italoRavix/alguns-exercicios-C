// Exercicio 08_07
// Programa que pega 4 string que representam inteiros de no maximo 9 digitos, os armazena em um array,
// os converte para inteiros, os soma e imprime. 

#include <stdio.h>
#include <stdlib.h>

#define NUMBER_OF_STRINGS 4
#define INTEGER_DECIMAL_SIZE 11
int main(void)
{
    char strings[NUMBER_OF_STRINGS][INTEGER_DECIMAL_SIZE]; // irá armazenar as strings que serao convertidas
    int integers[NUMBER_OF_STRINGS]; // armazena as os inteiros apos a conversão
    int total = 0;
    
    // pega os dados do usuário e armazena no array
    for(int i = 0; i < NUMBER_OF_STRINGS; i++)
    {
        printf("String %d: \n", i + 1);
        fgets(strings[i], INTEGER_DECIMAL_SIZE, stdin);
    } 
    
    //converte as strings em inteiros
    for(int i = 0; i < NUMBER_OF_STRINGS; i++)
    {
        integers[i] = atoi(strings[i]);
    } 
    
    // soma os valores
    for(int i = 0; i < NUMBER_OF_STRINGS; i++)
    {
        total += integers[i];
    }    
    
    // imprime o total
    printf("Total: %d\n", total);
    
}
