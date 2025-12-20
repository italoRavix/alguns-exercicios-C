// Exercicio 08_08
//

#include <stdio.h>
#include <stdlib.h>

#define NUMBER_OF_STRINGS 4
#define DOUBLE_SIZE 10
int main(void)
{
    char strings[NUMBER_OF_STRINGS][DOUBLE_SIZE]; // irá armazenar as strings que serao convertidas
    double doubles[NUMBER_OF_STRINGS]; // armazena as os inteiros apos a conversão
    double total = 0;
    
    // pega os dados do usuário e armazena no array
    for(int i = 0; i < NUMBER_OF_STRINGS; i++)
    {
        printf("String %d: \n", i + 1);
        fgets(strings[i], DOUBLE_SIZE, stdin);
    } 
    
    //converte as strings em inteiros
    for(int i = 0; i < NUMBER_OF_STRINGS; i++)
    {
        doubles[i] = atof(strings[i]);
    } 
    
    // soma os valores
    for(int i = 0; i < NUMBER_OF_STRINGS; i++)
    {
        total += doubles[i];
    }    
    
    // imprime o total
    printf("Total: %f\n", total);
    
}
