// Exercicio 12_08
// Este programa recebe uma expressão em notação infixa e a converte para uma expressão em notação pós-fixa.

#include "../StackListFunction/stackCharFunctions.h"
#include <stdio.h>
#include <ctype.h>

#define LEFT_PARENTESIS '('
#define RIGHT_PARENTESIS ')'
#define SPACE ' '

// prototipos
void convertToPostfix(char infix[], char postfix[]);
int isOperator(char c);
int precedence(char operator1, char operator2);
void insertRightParentesis(char* array);
int whichPrecedence(int operator);
void printPostfix(char* array);

#define ARRAY_SIZE 20

int main(void)
{   

    char infix[ARRAY_SIZE]; // array que armazena a entrada do usuario em notaçao infixa    
    char postfix[ARRAY_SIZE]; // array que armazena a conversao da entrada do usuario em notaçao pos-fixa
    unsigned infixIndex = 0;
    unsigned postfixIndex = 0;
    
    StackNodePtr top = NULL; // inicializa o topo
    
    push(&top, LEFT_PARENTESIS); //1
    printf("Insira uma expressão valida: ");
    fgets(infix, ARRAY_SIZE, stdin); // pega a entrada do usuario
    insertRightParentesis(infix); //2
    
    while(!isEmpty(top))
    {
        if(isdigit(infix[infixIndex]))
        {
            postfix[postfixIndex] = infix[infixIndex];
            postfixIndex++;
        }
        
        else if(infix[infixIndex] == LEFT_PARENTESIS)
        {
            push(&top, infix[infixIndex]);
        }
            
        else if(isOperator(infix[infixIndex]))
        {
                while(isOperator(stackTop(top)) && precedence(stackTop(top), infix[infixIndex]))
                {
                    postfix[postfixIndex] = pop(&top);
                    postfixIndex++;
                }
                push(&top, infix[infixIndex]);  
        }
        
        else if(infix[infixIndex] == RIGHT_PARENTESIS)
        {
            while(stackTop(top) != LEFT_PARENTESIS)
            {
                postfix[postfixIndex] = pop(&top);
                postfixIndex++;
            }
            pop(&top);
        }
            
        
        infixIndex++;
    }
    
    infix[infixIndex] = '\0';
    printf("Conversão em Postfix: ");
    printPostfix(postfix);

//  ALGORTIMO PARECE CORRETO MAS AINDA NAO FOI TESTADO, TODOS OS ELSE IF

    return 0;
}

void insertRightParentesis(char* array)
{
    int i = 0;
    
    while(array[i] != '\0')
    {   
        if(array[i] == '\n')
            array[i] = RIGHT_PARENTESIS;
        i++;
    }
}

int isOperator(char c)
{
    if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '%')
        return 1;
    
    return 0;
}

int precedence(char operator1, char operator2)
{
    if(whichPrecedence(operator1) >= whichPrecedence(operator2))
        return 1;
        
    return 0;
}

int whichPrecedence(int operator)
{
    enum {NUM_MAX_OPERATORS = 3, NUM_PRECEDENCES_OPERATORS = 3};
    
    // define os contadores e o nivel de precedencia de cada operador, os indices dos arrays internos define a precedencia
    int i, j, operators[][NUM_MAX_OPERATORS] = {{'+', '-'}, {'*', '/', '%'}, {'^'}};
    
    // se o operador for
    for(i = 0; i < NUM_PRECEDENCES_OPERATORS; i++)
    {
        for(j = 0; j < NUM_MAX_OPERATORS; j++)
        {
            if(operator == operators[i][j])
                return i;
        }
    }
}

void printPostfix(char* array)
{
    int i;
    
    while(array[i] != '\0' && array[i] != ' ')
    {
        putchar(array[i]);
        putchar(' ');
        i++;
    }
    
    putchar('\n');
}
