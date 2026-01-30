// Exercicio 12_08
// Adiciona funçoes que calculam a soma e a média dos valores armazenados em uma lista ligada

#include "../LinkedListFunction/linkedListFunctions.h"
#include <time.h>
#include <math.h>

#define NUMS 15
#define RANDOM_RANGE 100

// prototipos
double meanList(ListNodeIntPtr currentPtr);
unsigned sumList(ListNodeIntPtr currentPtr);

int main(void)
{
    ListNodeIntPtr startPtr = NULL; // inicialmente não existem nós
    unsigned i; // contador
    
    srand(time(NULL));
    
    for(i = 0; i < NUMS; i++)
    {
        insertInt(&startPtr, rand() % RANDOM_RANGE);
    }
    
    if(isEmptyInt(startPtr))
        printf("Lista Vazia");
        
    else
    {
        printListInt(startPtr);
        printf("A soma é: %d\n", sumList(startPtr));
        printf("A média é: %.2f\n", meanList(startPtr));        
    }
    
    return 0;
}

unsigned sumList(ListNodeIntPtr currentPtr)
{
    int sum = 0;

    // calcula a soma armazenada nos nós
    while(currentPtr != NULL)
    {
        sum += currentPtr->data;
        currentPtr = currentPtr->nextPtr;
    }
        
    return sum;     
}

double meanList(ListNodeIntPtr currentPtr)
{
    int ammountNodes = 0;
    int sum = sumList(currentPtr); // armazena a quantidade
        
    // calcula o numero de nos    
    while(currentPtr != NULL)
    {
        ammountNodes++;
        currentPtr = currentPtr->nextPtr;
    }
        
    return (double) sum / ammountNodes;  
}
