// Exercicio 10_10
// Este programa testa o deslocamento à direita em uma variavel int.
// A função displayBits imprime um inteiro como binario.


#include <stdio.h>
#include "../General Functions/functions_10.h"

int main(void)
{
    int x = 423454;
    
    printf("Valor inicial\n");
    displayBitsInt(x, TYPE_INT);
    
    x >>= 1;
    
    printf("Valor apos deslocamento à direita\n");
    displayBitsInt(x, TYPE_INT);
}

