// Exercicio 13_08
// Este programa define uma macro para imprimir valores de strings

#include <stdio.h>
#define PRINT(x) printf(# x "\n")

int main (void)
{
    PRINT(Um valor qualquer para ser imprimido...);
    return 0;
}
