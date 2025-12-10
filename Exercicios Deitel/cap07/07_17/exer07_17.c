// Exercicio 7_17
// Simulação: a tartaruga e a lebre
//
// O programa a seguir simula uma corrida entre a tartaruga e a lebre

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <unistd.h> // Usando a funçao sleep para fazer o sistema esperar 1 segundo para que srand() nao gere sempre o mesmo valor de passada para tartarura e lebre
#define TAMANHO_CORRIDA 70

// passadas da tartaruga
#define CAMINHA_RAPIDAMENTE 3
#define ESCORREGA -6
#define CAMINHA_LENTAMENTE 1

// passadas da lebre
#define DORME 0
#define SALTO_GRANDE 9
#define ESCORREGA_BASTANTE -12
#define SALTO_PEQUENO 1
#define ESCORREGA_POUCO -2

// prototipos
void corrida();
int passadaTartaruga();
int passadaLebre();

int main(void)
{
    corrida();
}

void corrida()
{
    int T = 1; // representa a posição da tartaruga
    int L = 1; // representa a posição da lebre
    char * simbolo[1]; // representa o simbolo 'branco'
    
    while(T < TAMANHO_CORRIDA && L < TAMANHO_CORRIDA)  
    {
        // atualizaçao de posiçao da tartaruga
        T += passadaTartaruga();
            if(T <= 0)
                T = 1;
                
            if(T > 70)
                T = 70;
                
        // atualizaçao de posiçao da lebre
        L += passadaLebre();
            if(L <= 0)
                L = 1;   
                
            if(L > 70)
                L = 70;
                
        simbolo[0] = "-"; // reinicia a cada iteraçao o simbolo 'branco'
        int contadorSimbolo = 1; // indica o indice do simbolo a ser impresso a cada loop
        
        while(contadorSimbolo <= 70)
        {
            if(contadorSimbolo != T && contadorSimbolo != L)
                printf("%s ", simbolo[0]);
            else
            {
                if(T == L)
                {
                    simbolo[0] = "AI!"; 
                    printf("%s", simbolo[0]);
                }
                else
                {
                    if(contadorSimbolo == T)
                        printf("%c", 'T');
                    if(contadorSimbolo == L)
                        printf("%c", 'L');
                } 
            }
            
            contadorSimbolo++;               
        }
        
        int testeScanf;
        printf("\n");
            
        if(T >= TAMANHO_CORRIDA || L >= TAMANHO_CORRIDA)
        {
            if(T >= TAMANHO_CORRIDA && L >= TAMANHO_CORRIDA)
                printf("\nEmpate\n");
            else
            {
                if(T >= TAMANHO_CORRIDA)
                    printf("TARTARUGA VENCE!!! É ISSO AÍ!!!\n");
                if(L >= TAMANHO_CORRIDA)
                    printf("Lebre vence. Marmelada.\n");                        
            }
        }
    }
}

int passadaTartaruga()
{
    int passada;
    sleep(1);
    
    srand(time(NULL));
    
    passada = rand() % 10 + 1;
    
    if(passada <= 5)
        return CAMINHA_RAPIDAMENTE;
    else if(passada > 5 && passada <= 7)
        return ESCORREGA;
    else
        return CAMINHA_LENTAMENTE;
}

int passadaLebre()
{
    int passada;
    sleep(1);
    
    srand(time(NULL));
    
    passada = rand() % 10 + 1;
    
    if(passada <= 2)
        return DORME;
    else if(passada > 2 && passada <= 4)
        return SALTO_GRANDE;
    else if(passada > 4 && passada <= 5)
        return ESCORREGA_BASTANTE;
    else if(passada > 5 && passada <= 8)
        return SALTO_PEQUENO;        
    else
        return ESCORREGA_POUCO;
}
