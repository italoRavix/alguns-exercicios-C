// Exercicio 11_15
// Esse programa trabalha uma sequencia de caracteres e dois arquivos. Pode-se mandar a sequencia
// da entrada padrao para a saida padrao ou de um arquivo de entrada para um arquivo de saida.
#include <stdio.h>

void cleanBuffer(void);
    
int main(void)
{
    FILE *iFPtr, *oFPtr; // ponteiros para os arquivos de entrada e saida
    char c; // variavel que mantem o caractere digitado pelo usuario
    int choose; // variavel que mantem a escolha do usuario
    enum {STANDARD = 1, FILE = 2} choice;
    char sentence[1000]; // cria array de char
    int i = 0; // inicializa o contador
    
    puts("Digite sua escolha");
    puts("[1] Ler da entrada padrao e gravar na entrada padrao");
    puts("[2] Ler de arquivo e gravar em arquivo"); 
    scanf("%d", &choose);
    
    switch(choose)
    {
        case STANDARD:
            // pede que o usuario digite uma linha de texto
            puts("Digite uma linha de texto");
            cleanBuffer(); // limpa o '\n' ignorado por scanf                
            while((c = fgetc(stdin)) != '\n')
                sentence[i++] = c;
                
            sentence[i] = '\0';    
            puts("\nA linha digitada foi:");
            fputs(sentence, stdout);
            putchar('\n');
            
            break;
        
        case FILE:
            const int SIZE_NAME = 20;
            char fileInputName[SIZE_NAME];
            char fileOutputName[SIZE_NAME];     
            
            puts("Digite o nome do arquivo de entrada");
            scanf("%s", fileInputName);    
            
            if((iFPtr = fopen(fileInputName, "r")) == NULL)
            {
                printf("Erro ao abrir arquivo de entrada.\n");
                break;
            }
            
            puts("Digite o nome do arquivo de saida");
            scanf("%s", fileOutputName);    
            
            if((oFPtr = fopen(fileOutputName, "w")) == NULL)
            {
                printf("Erro ao abrir arquivo de saida.\n");
                break;
            }            

            cleanBuffer(); // limpa o '\n' ignorado por scanf                
            while((c = fgetc(iFPtr)) != EOF)
                sentence[i++] = c;
                
            sentence[i] = '\0';
            fputs(sentence, oFPtr);
            
            fclose(iFPtr);
            fclose(oFPtr);
            break;
    }
    
    return 0;
}

// permite que fgets funciona de forma apropriada apos o uso de scanf
void cleanBuffer(void)
{
    char c;
    while((c = getchar()) != '\n' && c != EOF);
}
