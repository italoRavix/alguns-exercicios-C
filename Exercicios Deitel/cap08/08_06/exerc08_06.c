// Exercicio 08_06
// Este programa recebe uma linha de texto e imprime totalmente maíusculo e totalmente minúsculo.

#include <stdio.h>
#include <ctype.h>
#define SIZE 100

int main(void)
{
    char s[SIZE];
    char *c; // armazena o endereço de cada caractere do array
    
    printf("Escreva algo: ");
    fgets(s, SIZE, stdin);
    
    
    c = s; // começa a apontar para s[0]
    while(*c != '\0')
        printf("%c", toupper(*c++));
        
    c = s; // começa a apontar para s[0]    
    while(*c != '\0')
        printf("%c", tolower(*c++));        
}
