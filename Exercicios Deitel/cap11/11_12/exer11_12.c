// Exercicio 11_12
// Esse programa é um sistema de gerenciamento de estoque simples usando um arquivo binario.
// O sistema adiciona, remove, atualiza e exibe os itens do arquivo.

#include <stdio.h>
#define NUM_RECORDS 100

// representa uma estrutura
struct tool
{
    unsigned id;
    char name[20];
    unsigned amount;
    double price;
} typedef Tool;

// prototipos
FILE *inicialize(FILE*);
void printTools(FILE *);
void insert(FILE *);
void delete(FILE *);   
void update(FILE *);
int enterChoice(void);

int main(void)
{
    FILE *fPtr = inicialize(fPtr); // inicializa o ponteiro fPtr
    unsigned choice; // armazena a escolha do usuario;
    
    enum options {PRINT = 1, INSERT, DELETE, UPDATE};
    
    if(fPtr == NULL)
        return -1;
    
    while((choice = enterChoice()) != 5)
    {
        switch(choice)
        {
            case PRINT:
                printTools(fPtr);
                break;
                
            case INSERT:
                insert(fPtr);            
                break;
                
            case DELETE:
                delete(fPtr);            
                break;
                
            case UPDATE:
                update(fPtr);            
                break;
        }
    }
    
    printf("Programa encerrado\n");
    
    return 0;
}

// inicializa o arquivo com 100 registros, se ele nao existe o cria.
FILE *inicialize(FILE *fPtr)
{
    Tool tool = {0, "", 0, 0.0};
    
    // ve se o arquivo existe, se nao existe o cria
    if((fPtr = fopen("hardware.dat", "rb+")) == NULL)
    {
        if((fPtr = fopen("hardware.dat", "wb+")) == NULL)
        {
            printf("Erro ao criar o arquivo.\n");
            return NULL;
        }
        
        else
        {
            for(int i = 0; i < NUM_RECORDS; i++)
                fwrite(&tool, sizeof(Tool), 1, fPtr);
        }
    }
    
    else
    {
        printf("Arquivo ja inicilizado antes.\n");
        
        // for(int i = 0; i < NUM_RECORDS; i++)
        //     fwrite(&tool, sizeof(Tool), 1, fPtr);
    }
    
    return fPtr;
}

// insere um registro no arquivo
void insert(FILE *fPtr)
{
    int flagIsOccupied = 1; // indica se um registro esta ocupado ou livre
    int flagHasMoreRecords; // indica se ha mais registros para serem lidos ou se é o fim do arquivo
    unsigned c = 0; // contador
    Tool tool;
    
    rewind(fPtr); // coloca o ponteiro no inicio
    while(flagIsOccupied && 1 == (flagHasMoreRecords = fread(&tool, sizeof(Tool), 1, fPtr)))
    {
        if(tool.id == 0)
            flagIsOccupied = 0;

        c++;
    }
    
    // se chegou ao fim do arquivo 
    if(!flagHasMoreRecords)
    {
        printf("Arquivo cheio.\n");
        return;
    }

    tool.id = c;
    printf("Insira o nome do produto, quantidade e valor: ");
    scanf("%s%u%lf", tool.name, &tool.amount, &tool.price);    
    
    fseek(fPtr, (tool.id - 1) * sizeof(Tool), SEEK_SET); // coloca o ponteiro no lugar certo para escrita    
    fwrite(&tool, sizeof(Tool), 1, fPtr);
}

// deleta um registro
void delete(FILE *fPtr)
{
    unsigned idSearched;
    printf("Insira o ID do produto a ser deletada ou [-1] para cancelar: ");
    scanf("%u", &idSearched);
    
    if(-1 == idSearched)
        return;
    
    Tool blankTool = {0, "", 0, 0.0};

    fseek(fPtr, (idSearched - 1) * sizeof(Tool), SEEK_SET); // coloca o ponteiro no lugar certo para escrita   
    fwrite(&blankTool, sizeof(Tool), 1, fPtr);
}

// atualiza um registro
void update(FILE *fPtr)
{
    enum option { NAME = 1, AMOUNT, PRICE , ALL};
    unsigned idSearched, choose;
    printf("Insira o ID do produto a ser atualizado ou [-1] para cancelar: ");
    scanf("%u", &idSearched);
    
    if(-1 == idSearched)
        return;    
    
    Tool tool;
    
    fseek(fPtr, (idSearched - 1) * sizeof(Tool), SEEK_SET); // coloca o ponteiro no lugar certo para escrita   
    fread(&tool, sizeof(Tool), 1, fPtr);  
    
    // verifica se a peça esta cadatrada
    if(tool.id == 0)
    {
        printf("Peça inexistente\n");
        return;
    }
    
    printf("Qual informaçao atualizar? \n[1] Nome\n[2] Quantidade\n[3] Preco\n[4] Tudo\n");
    scanf("%u", &choose);
    
    switch(choose)
    {
        case NAME:
            printf("Novo nome: ");
            scanf("%s", tool.name);
            break;
            
        case AMOUNT:
            printf("Nova quantidade: ");
            scanf("%u", &tool.amount);
            break;  
            
        case PRICE:
            printf("Novo preço: ");
            scanf("%lf", &tool.price);
            break;  
            
        case ALL:
            printf("Novos dados: ");
            scanf("%s%u%lf", tool.name, &tool.amount, &tool.price);   
            break;
    }

    fseek(fPtr, (idSearched - 1) * sizeof(Tool), SEEK_SET); // coloca o ponteiro no lugar certo para escrita   
    fwrite(&tool, sizeof(Tool), 1, fPtr);
}


// imprime todos os registros no arquivo
void printTools(FILE *fPtr)
{
    Tool tool; // armazena para a impressao
    
    rewind(fPtr); // coloca o ponteiro no inicio
    
    printf("%3s %-20s %6s %5s\n", "ID", "Nome", "Quant.", "Preço");         
    
    while(fread(&tool, sizeof(Tool), 1, fPtr) == 1)
    {
        // imprime apenas os registros com dados
        if(tool.id != 0)
            printf("%03u %-20s %6u %5.2lf\n", tool.id, tool.name, tool.amount, tool.price);     
    }
        
    putchar('\n');
}

int enterChoice(void)
{
    int menuChoice;
    
    printf("\nDigite sua escolha\n");
    printf("[1]: Exibir registros.\n");
    printf("[2]: Inserir registro.\n");
    printf("[3]: Deletar registro.\n");
    printf("[4]: Atualizar registro.\n");
    printf("[5]: Fechar Programa.\n");    
    
    scanf("%d", &menuChoice);
    return menuChoice;
}
