// Exercicio 10_10
// Este programa testa o deslocamento à direita em uma variavel int.
// A função displayBits imprime um inteiro como binario.


#include <stdio.h>
#include <limits.h>

#define INT_BITS CHAR_BIT * sizeof(int) // define o tamanho em bits de um inteiro

// protótipos
void displayBits(int x);

int main(void)
{
    int x = 423454;
    
    printf("Valor inicial\n");
    displayBits(x);
    
    x >>= 1;
    
    printf("Valor apos deslocamento à direita\n");
    displayBits(x);    
}

void displayBits(int x)
{
    int c; // contador
    
    // declara displayMask
    int displayMask = 1 << INT_BITS - 1;
    
    printf("%10d: ", x);
    
    // percorre os bits
    for(c = 1; c <= INT_BITS; c++)
    {
        putchar(displayMask & x ? '1' : '0'); // a mascara faz com que apenas o bit MSB importe a cada iteração, depois putchar imprime o valro correto do bit
        x <<= 1;
        
        if(c % 8 == 0)
            putchar(' ');
    }
    
    putchar('\n');
}
