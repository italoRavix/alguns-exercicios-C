// Exercicio 07_25
// Criando menu com um array de ponteiros para funções 
//
// O programa altera o programa da figura 6.22 para criar
// um menu interativo com o usuario usando um array de
// ponteiros para funções.

#include <stdio.h>
#define STUDENTS 3
#define EXAMS 4

// prototipos
void minimum(const int grades[][EXAMS], int pupils, int tests);
void maximum(const int grades[][EXAMS], int pupils, int tests);
void average(const int grades[][EXAMS], int pupils, int tests);
void printArray(const int grades[][EXAMS], int pupils, int tests);

// funçao main inicia a execuçao do programa
int main(void)
{
    int student; //contador de alunos
    int choose = 0; // armazena a escolha do usuario
    
    void (*processGrades[])(const int[][EXAMS], int, int) = {printArray, minimum ,maximum, average};
    
    // inicializa notas de aluno para três alunos (linhas)
    const int studentGrades[STUDENTS][EXAMS] = 
    {{ 77, 68, 86, 73},
     {96, 87, 89, 78},
     {70, 90, 86, 81}};

        printf("\nDigite uma escolha:\n0  Imprime o array de notas\n1  Acha a menor nota\n2  Acha a maior nota\n3  Imprime a média de todos os testes para cada aluno\n4  Encerra o programa\n");
        scanf("%d", &choose);
        
    while(choose >=0 && choose < 4){
        (*processGrades[choose])(studentGrades, STUDENTS, EXAMS);
        printf("\nDigite uma escolha:\n0  Imprime o array de notas\n1  Acha a menor nota\n2  Acha a maior nota\n3  Imprime a média de todos os testes para cada aluno\n4  Encerra o programa\n");
        scanf("%d", &choose);
    }    
}

void minimum(const int grades[][EXAMS], int pupils, int tests)
{
    int i; // contador de alunos
    int j; // contador de exames
    int lowGrade = 100; // inicializa com o maior valor possivel
    
    // loop pelas linhas de nota
    for(i = 0; i < pupils; i++)
    {
        // loop pelas colunas de nota
        for(j = 0; j < tests; j++)
        {
            if(grades[i][j] < lowGrade)
                lowGrade = grades[i][j];
        }
    }
    
    // determina o menor valor de nota
    printf("Menor nota: %d\n", lowGrade);
}

void maximum(const int grades[][EXAMS], int pupils, int tests)
{
    int i; // contador de alunos
    int j; // contador de exames
    int highGrade = 0; // inicializa com o menor valor possivel
    
    // loop pelas linhas de nota
    for(i = 0; i < pupils; i++)
    {
        // loop pelas colunas de nota
        for(j = 0; j < tests; j++)
        {
            if(grades[i][j] > highGrade)
                highGrade = grades[i][j];
        }
    }
    
    // determina o maior valor de nota
    printf("Maior nota: %d\n", highGrade);
}

void average(const int grades[][EXAMS], int pupils, int tests)
{
    int i; // contador de alunos
    int j; // contador de exames
    int total;
    
    for(int i = 0; i < pupils; i++)
    {
        total = 0;
        
        // soma todas as notas para um aluno
        for(j = 0; j < tests; j++)
            total += grades[i][j];
        
        printf("A nota média do aluno %d é %.2f\n", i, (double) total / tests);
    }
}

void printArray(const int grades[][EXAMS], int pupils, int tests)
{
    int i; // contador de aluno
    int j; // contador de exame
    
    // mostra o cabeçalhos de coluna
    printf("O array é: \n");
    printf("                [0]  [1]  [2]  [3]");
    
    // mostra notas em formato tabular
    for(i = 0; i < pupils; i++)
    {
        // mostra label para linha
        printf("\nstudentGrades[%d]", i);
        
        // mostra notas para um aluno
        for(j = 0; j < tests; j++)
        {
            printf("%-5d", grades[i][j]);
        }
    }
    printf("\n\n");
}
