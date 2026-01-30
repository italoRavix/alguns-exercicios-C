// Exercicio 12_07
// Esse programa adiciona ao exemplo do livro uma funçao que mescla duas listas de inteiros
#include <stdio.h>
#include <stdlib.h>

// estrutura autorreferenciada
struct listNode {
    int data;
    struct listNode *nextPtr;
};

typedef struct listNode ListNode; // sinonimo de struct listNode
typedef ListNode *ListNodePtr; // sinonimo de ListNode*

// prototipos
void insert(ListNodePtr *sPtr, int value);
int delete(ListNodePtr *sPtr, int value);
int isEmpty(ListNodePtr sPtr);
void printList(ListNodePtr currentPtr);
void instructions(void);
ListNodePtr merge(ListNodePtr *sPtr1, ListNodePtr sPtr2);

int main(void)
{
    ListNodePtr startPtr1 = NULL; // inicialmente não existem nós
    ListNodePtr startPtr2 = NULL; // inicialmente não existem nós
    
    int choice; // escolha do usuário
    int item; // int inserido pelo usuário
    
    instructions(); // exibe o menu
    printf("? ");
    scanf("%d", &choice);
    
    // loop enquanto usuário não escolhe 3
    while(choice != 6)
    {
        switch(choice)
        {
            case 1:
                printf("Digite um inteiro: ");
                scanf("%d", &item);
                insert(&startPtr1, item); // insere item na lista
                printList(startPtr1);
                break;
                
            case 2:
                if(!isEmpty(startPtr1))
                {
                    printf("Digite o inteiro a ser excluido: ");
                    scanf("%d", &item);
                    
                    // se caractere for encontrado, é removido
                    if(delete(&startPtr1, item))
                    {
                        printf("%d deleted. \n", item);
                        printList(startPtr1);
                    }
                    else
                        printf("%d não encontrado.\n\n", item);
                }
                else
                    printf("Lista está vazia.\n\n");
                break;
                
            case 3:
                printf("Digite um inteiro: ");
                scanf("\n%d", &item);
                insert(&startPtr2, item); // insere item na lista
                printList(startPtr2);
                break;
                
            case 4:
                if(!isEmpty(startPtr2))
                {
                    printf("Digite o inteiro a ser excluido: ");
                    scanf("%d", &item);
                    
                    // se caractere for encontrado, é removido
                    if(delete(&startPtr2, item))
                    {
                        printf("%d deleted. \n", item);
                        printList(startPtr2);
                    }
                    else
                        printf("%d não encontrado.\n\n", item);
                }
                else
                    printf("Lista está vazia.\n\n");
                break;
                
            case 5:
                printList(merge(&startPtr1, startPtr2));
                startPtr2 = NULL;
                break;
                
            default:
                printf("Opção inválida.\n\n");
                instructions();
                break;
        }
        
        printf("? ");
        scanf("%d", &choice);        
    }
    
    return 0;
}

void insert(ListNodePtr *sPtr, int value)
{
    ListNodePtr newPtr; // ponteiro para o novo nó
    ListNodePtr previousPtr; // ponteiro par ao nó anterior na lista
    ListNodePtr currentPtr; // ponteiro nó atual na lista
    
    newPtr = malloc(sizeof(ListNode)); // cria o nó
    
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

int delete(ListNodePtr *sPtr, int value)
{
    ListNodePtr previousPtr;
    ListNodePtr currentPtr;
    ListNodePtr tempPtr;
    
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

void instructions(void)
{
    printf("Digite sua escolha:\n 1 para inserir um elemento na lista 1.\n 2 para excluir um elemento da lista 1. \n 3 para inserir um elemento na lista 2.\n 4 para excluir um elemento da lista 2.\n 5 Mescla ambas as listas na lista 1.\n 6 encerra o programa.\n");
}

int isEmpty(ListNodePtr sPtr)
{
    return sPtr == NULL;
}

void printList(ListNodePtr currentPtr)
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

// mescla duas listas e as organiza
ListNodePtr merge(ListNodePtr *sPtr1, ListNodePtr sPtr2)
{
    ListNodePtr currentPtr2 = sPtr2;
    
    // cada nó da segunda lista é inserido no local correto da lista 1 
    while(currentPtr2 != NULL)
    {
        insert(sPtr1, currentPtr2->data);
        currentPtr2 = currentPtr2->nextPtr;
    }
    
    return *sPtr1;
}
