// Exercicio 10_21
// Esse programa coleta e imprime dados de um paciente

#include "healthFunctions.h"
#include <string.h> // Necessário para sleep()
#define NAME_SIZE 15

// representa um perfil de um paciente
struct 
{
    char name[NAME_SIZE];
    char surname[NAME_SIZE];
    char sex;
    Date birth;
    double height;
    double weight;
    
} typedef HealthProfile;

void removeNewLine(char* string);

int main(void)
{
    HealthProfile italo = {"Italo", "Tadewisk", 'M', {SEPTEMBER, 8, 2002}, 1.80, 70.0,};
    
    printf("Insira os dados do paciente\n");
    
    printf("Nome: ");
    fgets(italo.name, NAME_SIZE, stdin);
    italo.name[strcspn(italo.name, "\n")] = '\0';
    
    printf("Sobrenome: ");
    fgets(italo.surname, NAME_SIZE, stdin);
    italo.surname[strcspn(italo.surname, "\n")] = '\0';    
    
    printf("Sexo: ");
    scanf("%c", &italo.sex);
    
    unsigned m, d, y;
    printf("Data de nascimento formato MM-DD-AA: ");
    scanf("%u-%u-%u", &m, &d, &y);    
    italo.birth.month = m;
    italo.birth.day = d;
    italo.birth.year = y;    
    
    printf("Altura e peso separado por espaço: ");
    scanf("%lf %lf", &italo.height, &italo.weight);     
    
    
    printf("\nDADOS \nNome: %s %s\nSexo: %c\nNascimento: %02u/%02u/%u\nAltura: %.2f\nPeso: %.2f\n", italo.name, italo.surname, italo.sex, italo.birth.month, italo.birth.day, italo.birth.year, italo.height, italo.weight);
    
    printf("Idade: %u\n", ageCalculate(italo.birth));
    showBmiStatus( italo.weight, italo.height);
    showIdealHeartRate(italo.birth);
    
    return 0;
}
