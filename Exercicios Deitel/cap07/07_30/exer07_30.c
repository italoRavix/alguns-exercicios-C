// Exercicio 07_30
// Um menu interativo com o usuário que faz o cálculo da circunferencia de um circulo, calculo da área de um circulo ou calculo do volume
// de uma esfera. Utiliza o raio que o usuário fornecer para fazer o calculo selecionado.
//
// Para implementação foi utilizado um array de ponteiros para funçoes. O usuario escolhe uma opção, que é um numero inteiro, e essa opção
// é utilizada para selecionar o indice do array que armazena o ponteiro para a função.

#include <stdio.h>
#include <math.h>

// prototipos de funçoes de E/S
void printMenu(const int choose);
void printAnswer(const int choose, const double radius, double (*processRadius[])(const double radius));
void inputChoose(int * const choosePtr);
void inputRadius(double * const radiusPtr);

// prototipo de funçoes de tratamento de dados
double circleCircumference(const double radius);
double sphereVolume(const double radius);
double circleArea(const double radius);

// funçao principal do sistema
void calculate();

// definiçoes para o menu e para seleçao de funçao
#define MENU -1
#define CIRCLE_CIRCUMFERENCE 0
#define CIRCLE_AREA 1
#define SPHERE_VOLUME 2
#define QUIT 3

int main (void)
{
    calculate();
}

void calculate()
{
    double (*processRadius[])(const double radius) = {circleCircumference, circleArea, sphereVolume};
    
    int choose = MENU; // armazena a escolha do usuario
    double radius;
    
    printf("\n\n*** CALCULOS BASEADOS NO RAIO ***\n");    
    while(choose != QUIT)
    {
        printMenu(choose); // imprime o menu
        inputChoose(&choose); // obtem a escolha do usuario e altera o valor de choose
        
        if(choose != MENU && choose != QUIT)
        {
            printMenu(choose);
            inputRadius(&radius); //obtem o raio do usuario e altera o valor de radius
            printAnswer(choose, radius, processRadius);   
            choose = MENU;                        
        }
    }
    
    printMenu(QUIT);
}

void printMenu(const int choose)
{
        switch(choose)
        {
            case MENU:
                printf("\n\nSeleciona o calculo a ser realizado\n");
                printf("[%d] Circunferencia de um circulo\n", CIRCLE_CIRCUMFERENCE); 
                printf("[%d] Área de um circulo\n", CIRCLE_AREA);            
                printf("[%d] Volume de uma esfera\n", SPHERE_VOLUME);         
                printf("[%d] Sair\n", QUIT); 
                printf("Digite: ");
                break;
        
            case CIRCLE_CIRCUMFERENCE:
                printf("\n[%d] Circunferencia de um circulo\nInsira o raio: ", CIRCLE_CIRCUMFERENCE); 
                break;
                
            case CIRCLE_AREA:
                printf("\n[%d] Área de um circulo\nInsira o raio: ", CIRCLE_AREA); 
                break;
                
            case SPHERE_VOLUME:
                printf("\n[%d] Volume de uma esfera\nInsira o raio: ", SPHERE_VOLUME); 
                break;
                
            case QUIT:
                printf("\nPrograma encerrado\n\n");            
        }   
        
}

void printAnswer(const int choose, const double radius, double (*processRadius[])(const double radius))
{
    printf("Resultado: %lf", (*processRadius[choose])(radius));
}

// obtem a escolha do usuario
void inputChoose(int * const choosePtr)
{             
    scanf("%d", choosePtr);
    
    // valida a entrada do usuario
    if(*choosePtr <= MENU || *choosePtr > QUIT)
    {
        printf("Escolha uma opção válida");
        *choosePtr = MENU;    
    }
}

// obtem o raio do usuario
void inputRadius(double * const radiusPtr)
{
    scanf("%lf", radiusPtr);
    
    // valida a entrada do usuario
    if(*radiusPtr < 0)
    {
        printf("Não existe raio negativo!\nValor alterado para positivo.\n");
        *radiusPtr *= -1; // inverte o sinal se o raio passado for negativo    
    }    
}

// calcula a circunferencia de um circulo com base no raio passado como argumento
double circleCircumference(const double radius)
{
    return 2 * M_PI * radius;
}

// calcula a área de um circulo com base no raio passado como argumento
double circleArea(const double radius)
{
    return M_PI * radius * radius;
}

// calcula o volume de uma esfera com base no raio passado como argumento calcula 
double sphereVolume(const double radius)
{
    return (4.0/3.0) * M_PI * radius * radius * radius;
}
