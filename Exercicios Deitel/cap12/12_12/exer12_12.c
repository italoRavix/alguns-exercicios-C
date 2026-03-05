// Exercicio 12_08
// Este programa recebe uma expressão em notação infixa e a converte para uma expressão em notação pós-fixa.

#include "../StackListFunction/stackCharFunctions.h"
#include <stdio.h>

// prototipos
void convertToPostfix(char infix[], char postfix[]);
int isOperator(char c);
int precedence(char c);

#define ARRAY_SIZE 20

int main(void)
{   
    
    StackNodePtr top = NULL;
    push(&top, 'x');
    push(&top, 'y');
    push(&top, 'z');   
    pop(&top);
    
    printStack(top);
    
    
    //char infix[ARRAY_SIZE]; // array que armazena a entrada do usuario em notaçao infixa
    //char postfix[ARRAY_SIZE]; // array que armazena a conversao da entrada do usuario em notaçao pos-fixa
    
    //fgets(infix, ARRAY_SIZE, stdin); // pega a entrada do usuario
    

    return 0;
}
