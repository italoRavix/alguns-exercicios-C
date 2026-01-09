// Cabeçalho com as funçoes necessarias para o Exercicio 10_21

#include <stdio.h>
#include <time.h>

enum {JANUARY = 1, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER} typedef Month;

// representa uma data
struct
{
    Month month: 4;
    unsigned day: 5;
    unsigned year: 12;
    unsigned : 0;
    
} typedef Date;

// prototipos
double bmiCalculate(double, double);
void showBmiStatus(double, double);
unsigned ageCalculate(Date);
unsigned maxHeartRateCalculate(Date);
void showIdealHeartRate(Date);

// calcula o imc de um paciente
double bmiCalculate(double weight, double height)
{
    return weight / (height * height);
}

// calcula a idade do paciente
unsigned ageCalculate(Date birth)
{   
    struct tm *timeNow;;
    time_t seconds; // cria um time_t para representar tempo
    time(&seconds); // altera seconds colocando nele os segundos desde Unix Epoch
    timeNow = localtime(&seconds); // cria uma struct preenchida com dados de tempo e retorna um ponteiro para ela
    
    // calcula a diferença do ano atual com o ano de nascimento
    unsigned age = timeNow->tm_year + 1900 - birth.year;
    
    // verifica se o paciente ja fez aniversário
    if(birth.month >= timeNow->tm_mon + 1)
    {
        // se o mes de nascimento é igual ao mes atual e o dia de nascimento é maior que o dia atual ou o mês de nascimento é maior que o mes atual 
        if(birth.month == timeNow->tm_mon + 1 && birth.day > timeNow->tm_mday || birth.month > timeNow->tm_mon)
            --age;
    }
    
    return age;
}

unsigned maxHeartRateCalculate(Date birth)
{
    return 220 - ageCalculate(birth);
}

// exibe o status de IMC de um paciente
void showBmiStatus(double weight, double height)
{
    // representa medidas-chave para o calculo
    enum {UNDERWEIGHT = 18, NORMAL = 25, OVERWEIGHT = 30} typedef BmiStatus;
    unsigned bmi = bmiCalculate(weight, height);
    
    printf("Status IMC: ");
    
    if(bmi <= UNDERWEIGHT)
        printf("Abaixo do peso.");
        
    else if(bmi > UNDERWEIGHT && bmi <= NORMAL)
        printf("Normal");
        
    else if(bmi > NORMAL && bmi <= OVERWEIGHT)
        printf("Acima do peso.");
        
    else
        printf("Obeso.");
        
    putchar('\n');
}

void showIdealHeartRate(Date birth)
{
    unsigned maxHeartRate = maxHeartRateCalculate(birth);
    
    printf("Frequencia Maxima: %d\nFaixa ideal: %.2f - %.2f", maxHeartRate, maxHeartRate * 0.5, maxHeartRate * 0.85);
    putchar('\n');
}
