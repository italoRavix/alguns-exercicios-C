//
//

#include <stdio.h>

// pre configuraçoes
#define MEMORY_SIZE 100
#define SENTINELA -99999

// codigos de operaçao
#define READ 10
#define WRITE 11
#define LOAD 20
#define STORE 21
#define ADD 30
#define SUBTRACT 31
#define DIVIDE 32
#define MULTIPLY 33
#define BRANCH 40
#define BRANCHNEG 41
#define BRANCHZERO 42
#define HALT 43

void simpletron();

int main(void)
{
    simpletron();
}

void simpletron()
{
    // simuela a memoria do Simpletron
    int memory[MEMORY_SIZE] = {0};
    
    // registradores
    int accumulator = 0; // uso geral
    int instructionCounter = 0; // armazena o local da memoria que contem a instruçao sendo executada
    int operationCode = 0; // armazena os dois digitos da esquerda de uma palavra de instruçao
    int operand = 0; // armazena os dois digitos da direita de uma palavra de instruçao
    int instructionRegister = 0; // armazena a proxima instruçao a ser executada da memoria
    
    // logica do while
    int instruction = 0; // armazena as instrucoes que serao de entrada
    int numInstructions = 0; // armazena o numero de instruçoes de entrada
    
    printf("*** Bem vindo ao Simpletron! ***\n");
    printf("*** Favor digitar seu programa, uma instrução  ***\n");
    printf("*** (ou palavra de dados) por vez. Mostrarei   ***\n");
    printf("*** o número do local e uma interrogação (?)   ***\n");
    printf("*** Você, então deverá digitar a palavra para  ***\n");
    printf("*** esse local. Digite a sentinela -99999 para ***\n");
    printf("*** encerrar a entrada do seu programa.        ***\n\n");   
    
    // adiciona instruçoes à memoria do Simpletron
    while(instruction != SENTINELA)
    {
        printf("%02d ? ", numInstructions);
        scanf("%d", &instruction);
        
        if(instruction != SENTINELA)
        {
            memory[numInstructions] = instruction;
            numInstructions++;
        }    
    }
    
    printf("*** Carga do programa concluída ***\n");
    printf("*** Iniciando execução do programa ***\n");    
    
    // começa a execução
    for(int instructionCounter = 0; instructionCounter < numInstructions; instructionCounter++)
    {
        // atualiza os registradores
        instructionRegister = memory[instructionCounter];
        operationCode = instructionRegister / 100;
        operand = instructionRegister % 100;
        
        // imprime o estado atual
        printf("\nREGISTERS:\n");
        printf("accumulator               %04d\n", accumulator);
        printf("instructionCounter          %02d\n", instructionCounter);
        printf("instructionRegister       %04d\n", instructionRegister);    
        printf("operationCode               %02d\n", operationCode);    
        printf("operand                     %02d\n\n", operand);  
        
        // seleciona a operaçao
        switch(operationCode)
        {
            case READ:
                printf("INPUT: ");            
                scanf("%d", &memory[operand]);
                break;
                
            case  WRITE:
                printf("OUTPUT: %d\n", memory[operand]);
                break;  
                
            case LOAD:
                accumulator = memory[operand];
                break;
                
            case STORE:
                memory[operand] = accumulator;
                break;  

            case ADD:
                accumulator += memory[operand];
                break;
                
            case SUBTRACT:
                accumulator -= memory[operand];
                break;  
                
            case DIVIDE:
                accumulator /= memory[operand];
                break;
                
            case MULTIPLY:
                accumulator *= memory[operand];
                break;  

            case BRANCH:
                printf("BRANCH\n");
                break;
                
            case BRANCHNEG:
                printf("BRANCHNEG\n");
                break;  
                
            case BRANCHZERO:
                printf("BRANCHZERO\n");
                break;
                
            case HALT:
                printf("*** Execução do Simpletron encerrada ***\n\n");
                
                printf("MEMORY:\n\n");
                printf("     %4d  %4d  %4d  %4d  %4d  %4d  %4d  %4d  %4d  %4d\n", 0, 1, 2, 3, 4, 5, 6, 7, 8, 9);
                
                for(int i = 0; i < MEMORY_SIZE; i++)
                {
                    if(i % 10 == 0)
                        printf("\n%3d  ", i);
                        
                    printf("%04d  ", memory[i]);
                }
                
                printf("\n\n");

                break;  
                
        }
        
    }
}
