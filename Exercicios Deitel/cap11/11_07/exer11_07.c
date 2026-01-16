// Exercicio 11_07 
//Esse programa atualiza um arquivo de contas de clientes de um banco a partir das informaçoes de outros dois arquivos. O arquivo
// 'oldmast.dat' representa o arquivo com as informaçoes antigas de saldo dos clientes. O arquivo 'trans.dat' representa as transaçoes
// nas contas. O arquivo 'newmast' representa a nova situaçao das contas dos clientes.
// O programa usa dois loops aninhandos para atualizar os valores e a mesma logica também para verificar se uma conta existe realmente.
// Foi usado um esquema de arquivos sequencial.

#include <stdio.h>

// representa uma conta
struct clientAccount
{
    int accountNum;
    char name[40];
    double currentBalance;
} typedef Account;

// representa uma transaçao
struct transaction
{
    int accountNum;
    double dollarAmount;
} typedef Transaction;

int main(void)
{
    FILE *ofPtr, *tfPtr, *nfPtr;
   
    if((tfPtr = fopen("trans.dat", "r")) == NULL || (ofPtr = fopen("oldmast.dat", "r")) == NULL || (nfPtr = fopen("newmast.dat", "w")) == NULL)
        printf("Erro ao abrir o arquivo.\n");
    
    else
    {      
        // cria as variaveis temporarias
        Transaction transaction;
        Account account;
        
        // reinicia os ponteiros para garantir que estejam no inicio ao começar o loop
        rewind(ofPtr);  
        rewind(nfPtr);
          
        while(fscanf(ofPtr, "%d%s%lf", &account.accountNum, account.name, &account.currentBalance) != EOF)
        {
            while(fscanf(tfPtr, "%d%lf", &transaction.accountNum, &transaction.dollarAmount) != EOF)
            {      
                if(account.accountNum == transaction.accountNum) // se acha correspondencia escreve em newmast
                    account.currentBalance += transaction.dollarAmount; // modifica o saldo           
            }   
            
        fprintf(nfPtr, "%d %s %.2f\n", account.accountNum, account.name, account.currentBalance);
            
            rewind(tfPtr); // reinicia o ponteiro para garantir que a cada iteraçao do loop exterior o ponteiro esteja no inicio              
        }
  
        // avalia se a conta da transferencia existe
        while(fscanf(tfPtr, "%d%lf", &transaction.accountNum, &transaction.dollarAmount) != EOF)
        {   
            int flagNoExists = 1; // indica se existe conta com um determinado numero
            rewind(ofPtr);
                      
            while(fscanf(ofPtr, "%d%s%lf", &account.accountNum, account.name, &account.currentBalance) != EOF && flagNoExists)
            {   
                if(transaction.accountNum == account.accountNum) 
                    flagNoExists = 0;
            }
            
            if(flagNoExists)
                printf("Registro de transação sem correspondencia para a conta numero: %d\n", transaction.accountNum);
        }
        
        // fecha os arquivos
        fclose(tfPtr);
        fclose(ofPtr);
        fclose(nfPtr);        
    }
}
    

/*
TESTAR SE FUNCIONA 

*/

