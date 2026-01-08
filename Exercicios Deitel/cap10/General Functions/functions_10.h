#include <stdio.h>
#include <stdio.h>
#include <limits.h>

#define INT_BITS CHAR_BIT * sizeof(int) // define o tamanho em bits de um inteiro
#define CHAR_BITS CHAR_BIT * sizeof(char)

#define NONE 0
#define TYPE_INT 1
#define TYPE_CHAR 2

void displayBits(int x, unsigned type);
unsigned decideSize(unsigned type);

// exibe os bits de um inteiro
void displayBits(int x, unsigned type)
{

    unsigned size = decideSize(type);
    
    if(size)
    {
        int c; // contador
        
        // declara displayMask
        int displayMask = 1 << size - 1;
        
        printf("%10d: ", x);
        
        // percorre os bits
        for(c = 1; c <= size; c++)
        {
            putchar(displayMask & x ? '1' : '0'); // a mascara faz com que apenas o bit MSB importe a cada iteração, depois putchar imprime o valro correto do bit
            x <<= 1;
            
            if(c % 8 == 0)
                putchar(' ');
        }
        
        putchar('\n');
        
        return;
    }
    printf("Tipo de dado invalido ou ainda não definido.\n");
}


// Decide quantos bits usar em displayBits
unsigned decideSize(unsigned type)
{
    switch(type)
    {
        case TYPE_INT:
            return INT_BITS;
            
        case TYPE_CHAR:
            return CHAR_BITS;
            
        default:
            return NONE; 
    }
}
