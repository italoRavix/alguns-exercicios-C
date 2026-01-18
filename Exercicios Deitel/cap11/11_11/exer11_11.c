// Esse programa cria 10 registros para pessoas e os insere em um arquivo.
//

#include <stdio.h>
#include <string.h>
#define NUM_PESSOAS 100

struct pessoa 
{
    char sobrenome[15];
    char nome[15];
    char idade[4];
};

// prototipos
void inicializar(FILE *);
void inserir(FILE *);
void exibir(FILE *);

int main(void)
{   
    FILE *fPtr;
    
    if((fPtr = fopen("nameage.dat", "wb+")) == NULL)
        printf("Impossivel abrir o arquivo.\n");
    else
    {
        // a
        inicializar(fPtr);
        
        // b
        for(int i = 0; i < 10; i++)
            inserir(fPtr);  
        
        exibir(fPtr);
    }

    return 0;
}

// inicializa o arquivo binario com 100 espaços 'em branco'
void inicializar(FILE *fPtr)
{
    int i; // contador    
    struct pessoa pessoa = {"unassigned", "", "0"};
    
    rewind(fPtr);
    
    for(i = 0; i < NUM_PESSOAS; i++)
        fwrite(&pessoa, sizeof(struct pessoa), 1, fPtr);       
}

// insere um registro
void inserir(FILE *fPtr)
{   
    int flagRegistroOcupado = 1;
    int c = 0; // contador
    struct pessoa pessoa, pessoaTemp;
    rewind(fPtr);
    
    printf("Insira nome, sobrenome e idade: ");
    scanf("%s%s%s", pessoa.sobrenome, pessoa.nome, pessoa.idade);
    
    while(flagRegistroOcupado && fread(&pessoaTemp, sizeof(struct pessoa), 1, fPtr) == 1)
    {
        flagRegistroOcupado = strcmp("unassigned", pessoaTemp.sobrenome);
        c++;
    }
    
    if(!flagRegistroOcupado)
    {
        fseek(fPtr, (c - 1) * sizeof(struct pessoa), SEEK_SET);
        fwrite(&pessoa, sizeof(struct pessoa), 1, fPtr);        
    }
}

void exibir(FILE *fPtr)
{
    struct pessoa pessoa;
    rewind(fPtr);
    
    while(fread(&pessoa, sizeof(struct pessoa), 1, fPtr) == 1)
    {
        printf("%s %s %s\n", pessoa.nome, pessoa.sobrenome, pessoa.idade);
    }
    
    
}
