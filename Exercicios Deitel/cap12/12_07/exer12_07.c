// Exercicio 12_07
// Esse programa adiciona ao exemplo do livro uma funçao que mescla duas listas de inteiros

#include "../LinkedListFunction/linkedListFunctions.h"

// prototipos
void instructions(void);
ListNodeIntPtr merge(ListNodeIntPtr*, ListNodeIntPtr);

int main(void)
{
    ListNodeIntPtr startPtr1 = NULL; // inicialmente não existem nós
    ListNodeIntPtr startPtr2 = NULL; // inicialmente não existem nós
    
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
                insertInt(&startPtr1, item); // insere item na lista
                printListInt(startPtr1);
                break;
                
            case 2:
                if(!isEmptyInt(startPtr1))
                {
                    printf("Digite o inteiro a ser excluido: ");
                    scanf("%d", &item);
                    
                    // se caractere for encontrado, é removido
                    if(deleteInt(&startPtr1, item))
                    {
                        printf("%d deleted. \n", item);
                        printListInt(startPtr1);
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
                insertInt(&startPtr2, item); // insere item na lista
                printListInt(startPtr2);
                break;
                
            case 4:
                if(!isEmptyInt(startPtr2))
                {
                    printf("Digite o inteiro a ser excluido: ");
                    scanf("%d", &item);
                    
                    // se caractere for encontrado, é removido
                    if(deleteInt(&startPtr2, item))
                    {
                        printf("%d deleted. \n", item);
                        printListInt(startPtr2);
                    }
                    else
                        printf("%d não encontrado.\n\n", item);
                }
                else
                    printf("Lista está vazia.\n\n");
                break;
                
            case 5:
                printListInt(merge(&startPtr1, startPtr2));
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

void instructions(void)
{
    printf("Digite sua escolha:\n 1 para inserir um elemento na lista 1.\n 2 para excluir um elemento da lista 1. \n 3 para inserir um elemento na lista 2.\n 4 para excluir um elemento da lista 2.\n 5 Mescla ambas as listas na lista 1.\n 6 encerra o programa.\n");
}


// mescla duas listas e as organiza
ListNodeIntPtr merge(ListNodeIntPtr *sPtr1, ListNodeIntPtr sPtr2)
{
    ListNodeIntPtr currentPtr2 = sPtr2;
    
    // cada nó da segunda lista é inserido no local correto da lista 1 
    while(currentPtr2 != NULL)
    {
        insertInt(sPtr1, currentPtr2->data);
        currentPtr2 = currentPtr2->nextPtr;
    }
    
    return *sPtr1;
}
