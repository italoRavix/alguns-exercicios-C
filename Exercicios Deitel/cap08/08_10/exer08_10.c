// Exercicio 08_10
// Este programa recebe duas strings e verificase a primeira
// string digitada por um usuario é igual, maior ou menor

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void clearBuffer();

#define STRING_SIZE 50

int main(void)
{
    char s1[STRING_SIZE];
    char s2[STRING_SIZE];   
    int n;
    int comparator;
    
    printf("Digite a quantidade de caracteres que voce quer verificar\n");
    
    scanf("%d", &n);
    
    while(n <= 0)
    {
        printf("Insira um valor valido!\n");
        scanf("%d", &n);
    }

    printf("Digite 2 strings\n");
    clearBuffer();    
    fgets(s1, STRING_SIZE, stdin);
    fgets(s2, STRING_SIZE, stdin);  
    
    comparator = strncmp(s1, s2, n);
    
    if(comparator == 0)
        printf("Strings de mesmo tamanho.");
    else if(comparator > 0)
        printf("A primeira string é maior.");
    else
        printf("A primeria string é menor.");
    
    printf("\n");
    
    return 0;
}

void clearBuffer()
{
    char c;
    while((c = getchar()) != '\n' && (c = getchar()) != EOF);
}
