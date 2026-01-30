#include <stdio.h>
#include <stdlib.h>

// estruturra autorreferenciada que armazena um int
struct listNodeInt {
    int data;
    struct listNodeInt *nextPtr;
};

typedef struct listNodeInt ListNodeInt; // sinonimo de struct listNodeInt
typedef ListNodeInt *ListNodeIntPtr; // sinonimo de ListNodeInt*

// prototipos para as funçoes usadas na lista que armazena int
void insertInt(ListNodeIntPtr *sPtr, int value);
int deleteInt(ListNodeIntPtr *sPtr, int value);
int isEmptyInt(ListNodeIntPtr sPtr);
void printListInt(ListNodeIntPtr currentPtr);
void instructionsInt(void);


void insertInt(ListNodeIntPtr *sPtr, int value)
{
    ListNodeIntPtr newPtr; // ponteiro para o novo nó
    ListNodeIntPtr previousPtr; // ponteiro par ao nó anterior na lista
    ListNodeIntPtr currentPtr; // ponteiro nó atual na lista
    
    newPtr = malloc(sizeof(ListNodeInt)); // cria o nó
    
    if(newPtr != NULL)
    {
        newPtr->data = value; // coloca o valor no nó
        newPtr->nextPtr = NULL; 
        
        previousPtr = NULL;
        currentPtr = *sPtr;
        
        // loop para aint o local correto na lista
        while(currentPtr != NULL && value > currentPtr->data)
        {
            previousPtr = currentPtr; // caminha para...
            currentPtr = currentPtr->nextPtr; // ...proximo no
        }
        
        // insere novo nó no inicio da lista
        if(previousPtr == NULL)
        {
            newPtr->nextPtr = *sPtr;
            *sPtr = newPtr;
        }
        else // insere novo nó entre previousPtr e currentPtr
        {
            previousPtr->nextPtr = newPtr;
            newPtr->nextPtr = currentPtr;
        }
    }
    else
    {
        printf("%d não adicionado. Sem memória disponivel.\n", value);
    }
}

int deleteInt(ListNodeIntPtr *sPtr, int value)
{
    ListNodeIntPtr previousPtr;
    ListNodeIntPtr currentPtr;
    ListNodeIntPtr tempPtr;
    
    // exclui primeiro nó
    if(value == (*sPtr)->data)
    {
        tempPtr = *sPtr;
        *sPtr = (*sPtr)->nextPtr;
        free(tempPtr);
        return value;
    }
    else
    {
        previousPtr = *sPtr;
        currentPtr = (*sPtr)->nextPtr;
        
        // loop para aint local correto na lista
        while(currentPtr != NULL && currentPtr->data != value)
        {
            previousPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;
        }
        
        if(currentPtr != NULL)
        {
            tempPtr = currentPtr;
            previousPtr->nextPtr = currentPtr->nextPtr;
            free(tempPtr);
            return value;
        }
    }
    
    return '\0';
}

int isEmptyInt(ListNodeIntPtr sPtr)
{
    return sPtr == NULL;
}

void printListInt(ListNodeIntPtr currentPtr)
{
    if(currentPtr == NULL)
        printf("A lista está vazia.\n");
    else
    {
        printf("A lista é: ");
        
        while(currentPtr != NULL)
        {
            printf("%d --> ", currentPtr->data);
            currentPtr = currentPtr->nextPtr;
        }
        
        printf("NULL\n\n");
    }
}
