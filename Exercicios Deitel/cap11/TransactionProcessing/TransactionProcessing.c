//
//

#include<stdio.h>

struct clientData
{
    int acctNum;
    char lastName[15];
    char firstName[10];
    double balance;
};

// prototipos
int enterChoice(void);
void textFile(FILE *readPtr);
void updateRecord(FILE *fPtr);
void deleteRecord(FILE *fPtr);
void newRecord(FILE *fPtr);

int main(void)
{
    FILE *cfPtr;
    int choice;
    
    // fopen abre o arquivo, se o arquivo puder ser aberto
    if((cfPtr = fopen("credit.dat", "rb+")) == NULL)
        printf("Arquivo não pode ser aberto.\n");
        
    else
    {
        while((choice = enterChoice()) != 5)
        {
            switch(choice)
            {
                case 1:
                    textFile(cfPtr);
                    break;
                    
                case 2:
                    updateRecord(cfPtr);
                    break;
                    
                case 3:
                    newRecord(cfPtr);
                    break;
                    
                case 4:
                    deleteRecord(cfPtr);
                    break;
            }
        }
    }
    
    return 0;
}

void textFile(FILE *readPtr)
{
    FILE *writePtr;
    
    // cria cliente com informaçoes padrao
    struct clientData client = {0, "", "", 0.0};
    
    if((writePtr = fopen("accounts.txt", "w")) == NULL)
        printf("Erro ao abrir o arquivo\n");
        
    else
    {
        rewind(readPtr); // define o ponteiro para o inicio do arquivo
        fprintf(writePtr, "%-6s%-16s%-11s%10s\n", "Conta", "Sobrenome", "Nome", "Saldo");
        
        // copia todos os registros do arquivo de acesso aleatorio para o arquivo de texto
        while(!feof(readPtr))
        {
            int flagRead = fread(&client, sizeof(struct clientData), 1, readPtr);
            
            // verifica se numero da conta é zero (conta vazia) e se a leitura de um registro foi bem sucedida 
            if(client.acctNum && flagRead == 1)
                fprintf(writePtr, "%-6d%-16s%-11s%10.2f\n", client.acctNum, client.lastName, client.firstName, client.balance);
        }
        
        fclose(writePtr); // fecha o arquivo
    }
}

void updateRecord(FILE *fPtr)
{
    int account; // numero da conta
    double transaction; // valor da transaçao
    
    // cria clientData sem informaçao
    struct clientData client = {0, "", "", 0.0};
    
    // obtem o numero da conta para atualizar
    printf("Digite o numero da conta desejado (1-100): ");
    scanf("%d", &account);
    
    // move o ponteiro de arquivo para o registro correto
    fseek(fPtr, (account - 1) * sizeof(struct clientData), SEEK_SET);
    
    // le o registro do arquivo binario
    fread(&client, sizeof(struct clientData), 1, fPtr);
    
    // exibe erro se a conta nao existir
    if (client.acctNum == 0)
        printf("Conta #%d nao possui informaçoes\n", account);
        
    else
    {
        printf("%-6d%-16s%-11s%10.2f\n", client.acctNum, client.lastName, client.firstName, client.balance);
        
        // solicita do usuario o valor da transaçao
        printf("Digite cobrança (+) ou pagamento (-): ");
        scanf("%lf", &transaction);   
        client.balance += transaction; // atualiza o saldo do registro
        
        printf("%-6d%-16s%-11s%10.2f", client.acctNum, client.lastName, client.firstName, client.balance);
        
        fseek(fPtr, (account - 1) * sizeof(struct clientData), SEEK_SET);
    
        // grava o registro atualizado no arquivo binario
        fwrite(&client, sizeof(struct clientData), 1, fPtr);
    }
}

void deleteRecord(FILE *fPtr)
{
    int account; // numero da conta
    
    struct clientData blankClient = {0, "", "", 0.0}; // cria clientData sem informaçao
    struct clientData client; // armazena o registro lido do arquivo temporariamente para ser apagado
    
    // obtem o numero da conta para remover
    printf("Digite o numero da conta desejado (1-100): ");
    scanf("%d", &account);
    
    // move o ponteiro de arquivo para o registro correto
    fseek(fPtr, (account - 1) * sizeof(struct clientData), SEEK_SET);
    
    // le o registro do arquivo binario
    fread(&client, sizeof(struct clientData), 1, fPtr);
    
    // exibe erro se a conta nao existir
    if (client.acctNum == 0)
        printf("Conta #%d nao possui informaçoes\n", account);
        
    else
    {
        printf("%-6d%-16s%-11s%10.2f\n", client.acctNum, client.lastName, client.firstName, client.balance);
        
        fseek(fPtr, (account - 1) * sizeof(struct clientData), SEEK_SET);
    
        // grava o registro atualizado no arquivo binario
        fwrite(&blankClient, sizeof(struct clientData), 1, fPtr);
    }
}

void newRecord(FILE *fPtr)
{
    int account; // numero da conta
    
    struct clientData client = {0, "", "", 0.0}; // cria clientData sem informaçao
    
    // obtem o numero da conta para adicionar
    printf("Digite o numero da conta desejado (1-100): ");
    scanf("%d", &account);
    
    // move o ponteiro de arquivo para o registro correto
    fseek(fPtr, (account - 1) * sizeof(struct clientData), SEEK_SET);
    
    // le o registro do arquivo binario
    fread(&client, sizeof(struct clientData), 1, fPtr);
    
    // exibe erro se a conta nao existir
    if (client.acctNum != 0)
        printf("Conta #%d ja existe!\n", client.acctNum);
        
    else
    {
        printf("Insira o sobrenome, nome e saldo: ");
        scanf("%s%s%lf", client.lastName, client.firstName, &client.balance);
        
        client.acctNum = account;
        
        fseek(fPtr, (account - 1) * sizeof(struct clientData), SEEK_SET);

        // grava o registro atualizado no arquivo binario
        fwrite(&client, sizeof(struct clientData), 1, fPtr);
    }
}

int enterChoice()
{
    int menuChoice; // armazena a escolha do usuario
    
    // exibe o menu de opçoes
    printf("\nDigite sua escolhe\n");
    printf("1 - Armazena um arquivo de texto formatado de contas, chamado \"accounts.txt\" para impressão.\n");
    printf("2 - Atualiza uma conta\n");
    printf("3 - Inclui uma nova conta\n");    
    printf("4 - Exclui uma conta\n");    
    printf("5 - Termina o programa\n");    
    
    scanf("%d", &menuChoice);
    return menuChoice;
}
