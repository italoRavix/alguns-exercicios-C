#include <stdio.h>
#include <stdlib.h>

// estrutura autorreferenciada que armazena um char
struct stackNode {
    char data;
    struct stackNode *nextPtr;
};

// apelidos
typedef struct stackNode StackNode;
typedef StackNode *StackNodePtr;

// prototipos para as funçoes usadas na lista que armazena int
void push(StackNodePtr *topPtr, char value);
char pop(StackNodePtr *topPtr);
char stackTop(StackNodePtr topPtr);
int isEmpty(StackNodePtr topPtr);
void printStack(StackNodePtr topPtr);

void push(StackNodePtr *topPtr, char value)
{
    StackNodePtr newPtr; // ponteiro para o novo nó
    
    newPtr = malloc(sizeof(StackNode)); // cria o nó
    
    // insere o nó no topo da pilha
    if(newPtr != NULL)
    {
        newPtr->data = value;
        newPtr->nextPtr = *topPtr;
        *topPtr = newPtr;
    }
    else
    {
        printf("%c não adicionado. Sem memória disponivel.\n", value);
    }
}

char pop(StackNodePtr *topPtr)
{
    StackNodePtr tempPtr;
    char popValue;
  
    tempPtr = *topPtr;
    popValue = (*topPtr)->data;
    *topPtr = (*topPtr)->nextPtr;
    free(tempPtr);
    return popValue;
}

char stackTop(StackNodePtr topPtr)
{
    return topPtr->data;
}

int isEmpty(StackNodePtr topPtr)
{
    return topPtr == NULL;
}

void printStack(StackNodePtr currentPtr)
{
    if(currentPtr == NULL)
        printf("A pilha está vazia.\n");
    else
    {
        printf("A pilha é: ");
        
        while(currentPtr != NULL)
        {
            printf("%c --> ", currentPtr->data);
            currentPtr = currentPtr->nextPtr;
        }
        
        printf("NULL\n\n");
    }
}
