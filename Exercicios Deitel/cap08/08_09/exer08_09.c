// Exercicio 08_09
// Este programa recebe duas strings e verificase a primeira
// string digitada por um usuario é igual, maior ou menor 
// (alfabeticamente, no caso).

#include <stdio.h>
#include <string.h>

#define STRING_SIZE 50

int main(void)
{
    char s1[STRING_SIZE];
    char s2[STRING_SIZE];   
    int comparator;
    
    printf("Digite 2 strings: \n");
    fgets(s1, STRING_SIZE, stdin);
    fgets(s2, STRING_SIZE, stdin);  
    
    comparator = strcmp(s1, s2);
    
    if(comparator == 0)
        printf("Strings de mesmo tamanho.");
    else if(comparator > 0)
        printf("A primeira string é maior.");
    else
        printf("A primeria string é menor.");
    
    printf("\n");
    
    return 0;
}
