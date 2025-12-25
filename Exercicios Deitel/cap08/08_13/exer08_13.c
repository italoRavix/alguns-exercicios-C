// Exercicio 08_13
// Este programa converte a entrada do usuário em falso latim. Consiste em pegar as frases do
// usuário e colocar a primeira letra no final, após isso, adicionar a cada palavra com mais de dois caracteres o sufixo 'ei'. As frases não devem conter pontuações.

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 50
#define TEMP_CHAR_SIZE 100
#define LATIN_SUFIX "ei"
#define CHAR_NUMBER_MIN 1

int main(void)
{
    char frase[MAX_INPUT_SIZE];
    char *frasePtr; // ponteiro que armazena os tokens     
    
    printf("Insira a frase abaixo\n");
    fgets(frase, MAX_INPUT_SIZE, stdin);
    
    frase[strlen(frase) - 1] = '\0'; // remove o '\n' de frase pego por fgets
    
    frasePtr = strtok(frase, " ");
    
    while(frasePtr != NULL)
    {
        char tempStr[TEMP_CHAR_SIZE];  
        char initialChar; // armazena temporariamente o caractere inicial de cada token
        int i = 0;

        initialChar = tolower(frasePtr[0]); // armazena o primeiro caractere
        
        
        // enquanto nao encontra nulo em frasePtr, tempStr é povoada com os caracteres de frasePtr a exceção do primeiro
        while(frasePtr[i + 1] != '\0')
        {
            tempStr[i] = tolower(frasePtr[i + 1]);   
            i++;
        }       
        
        // adicionam o primeiro caractere e o caractere nulo no final
        tempStr[strlen(frasePtr) - 1] = initialChar;
        tempStr[strlen(frasePtr)] = '\0';
        
        // mantem palavras que iniciam em maiusculo
        if(isupper(frasePtr[0]))
            tempStr[0] = toupper(tempStr[0]);
        
        // adiciona sufixo apenas em palavras com mais de um caractere
        if(strlen(frasePtr) > CHAR_NUMBER_MIN)
            strcat(tempStr, LATIN_SUFIX);
        
        printf("%s ", tempStr);
        
        // atribui o proximo token a frasePtr
        frasePtr = strtok(NULL, " ");
    }
    printf("\n");
}

