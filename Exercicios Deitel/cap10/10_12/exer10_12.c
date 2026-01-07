// Exercicio 10_12
// Esse programa usa o deslocamento à esquerda para implementar uma funçao que multiplica um inteiro unsigned por 2

#include <stdio.h>
#include "../General Functions/functions_10.h"

unsigned power2(unsigned, unsigned);

int main(void)
{
    unsigned x = 3;
    unsigned pot = 5;
    
    printf("Variavel x antes de receber o valor de power (%d)\n", pot);
    displayBitsInt(x);
    
    x = power2(x, pot);
    printf("\nVariavel x aṕos de receber o valor de power (%d)\n", pot);    
    displayBitsInt(x);
    
    return 0;
}

unsigned power2(unsigned number, unsigned pot)
{
    return number << pot;
}
