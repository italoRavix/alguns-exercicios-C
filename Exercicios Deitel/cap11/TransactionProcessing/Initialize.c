// Esse programa cria e inicializa um arquivo binario para registros de cliente. 
//
#include <stdio.h>

#define NUMBER_OF_CLIENTS 100

// representa um registro de um cliente
struct clientData
{
    int acctNum;
    char lastName[15];    
    char firstName[10];
    double balance;
};

int main(void)
{
    int i; // contador
    
    // inicializa cada campo do registro cliente com valores 'em branco'
    struct clientData blankClient = {0, "", "", 0.0};
    
    FILE *cfPtr;
    
    if((cfPtr = fopen("credit.dat", "wb")) == NULL)
        printf("Não foi possivel abrir o arquivo.\n");
    else
    {
        // cria registros de clientes
        for(i = 0; i < NUMBER_OF_CLIENTS; i++)
            fwrite(&blankClient, sizeof(blankClient), 1, cfPtr);
  
        fclose(cfPtr);
    }
    return 0;
}
