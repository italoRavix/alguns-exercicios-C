// Exercicio 10_13
// Esse programa obtem do usuario dois caracteres, os exibe como binarios
// e depois compacta dois caracteres em um unsigned short (a maquina onde
// esse programa foi escrito e compilado usa unsigned shorts de 2 bytes, 
// tamanho conveninente para armazenar dois caracteres de 1 byte cada) e
// depois exibe o short resultante em bits.

#include <stdio.h>
#include "../General Functions/functions_10.h"

// prototipos
unsigned short compactCharacters(char, char);

int main(void)
{
    char c1, c2;
    
    printf("Digite dois caracteres separados por um espaço: \n");
    scanf("%c %c", &c1, &c2);
    
    displayBits(c1, TYPE_CHAR);
    displayBits(c2, TYPE_CHAR);    
    
    displayBits(compactCharacters(c1, c2), TYPE_U_SHORT);    
    
    return 0;
}


// compacta os dois caracteres em um
unsigned short compactCharacters(char c1, char c2)
{
    unsigned short compact = c1;
    
    compact <<= 8;
    
    return compact | c2;
}
