// Exercicio 07_12
// Programa de embralhamento e distribuição de cartas
//
// Minha ideia para esse exercicio consistiu em criar um array inteiro mao com 10 inteiros e armazenar nele
// as faces (indices pares) e naipes (indices impares) das 5 primeiras cartas sorteadas que representam uma mão.
// Como exemplo, a carta 'Rei de Copas' seria armazenada no array assim: um inteiro 12 no indice i e um inteiro 0 no indice i+1.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAMANHO_MAO 5

// prototipos
void embaralha(int[][13]);
void distribui(const int baralho[][13], const char *naipe[], const char *face[], int mao[]);

// prototipos para funçoes das questoes
void verificaUmPar(int mao[], const char *face[]);
void verificaDoisPares(int mao[], const char *face[]);
void imprimeCoordenadaMao(int mao[]);
void verificaUmaTrinca(int mao[], const char *face[]);

int main(void)
{
    // inicializa array naipe
    const char *naipe[4] = {"Copas", "Ouro", "Paus", "Espadas"};
    
    // inicializa array faces
    const char *face[13] = {"Ás", "Dois", "Tres", "Quatro", "Cinco", "Seis", "Sete", "Oito", "Nove", "Dez", "Valete", "Dama", "Rei"}; 
    
    // inicializa o array que representa a mao
    int mao[10];
    
    // inicializa array baralho
    int baralho[4][13] = {0};   
    
    srand(time (0)); // semente do gerador de numero aleatorio
    
    embaralha(baralho);
    
    distribui(baralho, naipe, face, mao);
    int maoTeste[10] = {12, 1, 12, 0, 1, 3, 1, 2, 1, 1}; // mao inicalizada manualmente para testes
    verificaDoisPares(maoTeste, face);
    imprimeCoordenadaMao(maoTeste);
    
}

void embaralha(int baralho[][13])
{
    int linha;
    int coluna;
    int carta;
    
    // para cada uma das 52 cartas, escolhe slot de deck aleatoriamente
    for(carta = 1; carta <= 52; carta++)
    {
        //escolhe novo local aleatorio ate que um lot nao ocupado seja encontrado
        do
        {
            linha = rand() % 4; 
            coluna = rand() % 13;
        } while(baralho[linha][coluna] != 0);
        
        // coloca o numero da carta no slot escolhido do baralho
        baralho[linha][coluna] = carta;
    }       
}

// distribui cartas do baralho em uma mão
void distribui(const int baralho[][13], const char *naipe[], const char *face[], int mao[])
{
    int carta;
    int linha;
    int coluna;
    
    // distribui cada uma das 5 cartas de uma mao de poker
    for(carta = 1; carta <= TAMANHO_MAO; carta++)
    {
        // loop pelas linhas de baralho
        for(linha = 0; linha < 4; linha++)
        {
            // loop pelas colunas de baralho
            for(coluna = 0; coluna < 13; coluna++)
            {
                // se slot contem a carta atual, mostra a carta
                if(baralho[linha][coluna] == carta)
                {
                    printf("%s de %s %c", face[coluna], naipe[linha], '\n');
                    
                    // as duas instruçoes a seguir foram adicionas para solucionar os exercicios
                    mao[(carta - 1) * 2] = coluna; //armazena a coordenada da coluna nos indices pares (faces)
                    mao[carta * 2 - 1] = linha; // armazena a coordenada da linha nos indices impares (naipes)
                }    
            }
        }   
    }
}

// a
// verifica se há um par na mao 
void verificaUmPar(int mao[], const char *face[])
{
    int faceEscolhida; // armazena a face escolhida para ser comparada
    int faceComparada; // armazena as faces que serao comparadas com a escolhida
    
    for(faceEscolhida = 0; faceEscolhida < TAMANHO_MAO * 2; faceEscolhida = faceEscolhida + 2)
    {
        for(faceComparada = faceEscolhida + 2; faceComparada < TAMANHO_MAO * 2; faceComparada = faceComparada + 2)
        {
            if (mao[faceEscolhida] == mao[faceComparada])
            {
                printf("\nPar achado: %s = %s\n", face[mao[faceEscolhida]], face[mao[faceComparada]]);
                return;
            }
        }
    }
}

// b
// verifica se há dois pares na mao 
void verificaDoisPares(int mao[], const char *face[])
{
    int faceEscolhida; // armazena a face escolhida para ser comparada
    int faceComparada; // armazena as faces que serao comparadas com a escolhida
    int existeUmPar = 0; // sentinela que diz se ja existe um par
    
    int facePrimeiroPar = -1; // usado no if para impedir que uma face que ja gerou um par seja validada novamente, impede que a funçao aceite 3 faces como se fossem 2 pares
    
    for(faceEscolhida = 0; faceEscolhida < TAMANHO_MAO * 2; faceEscolhida = faceEscolhida + 2)
    {
        for(faceComparada = faceEscolhida + 2; faceComparada < TAMANHO_MAO * 2; faceComparada = faceComparada + 2)
        {
            if (mao[faceEscolhida] == mao[faceComparada] && mao[faceEscolhida] != facePrimeiroPar)
            {
                printf("Par %d achado: %s = %s\n", existeUmPar + 1, face[mao[faceEscolhida]], face[mao[faceComparada]]);
                facePrimeiroPar = mao[faceEscolhida];
                if(existeUmPar)
                  return;
                
                existeUmPar = 1;
            }
        }
    }
}

// c
// verifica se há uma trinca na mao 
void verificaUmaTrinca(int mao[], const char *face[])
{
    int faceEscolhida; // armazena a face escolhida para ser comparada
    int faceComparada; // armazena as faces que serao comparadas com a escolhida
    int faceComparada2; // armazena as faces que serao comparadas apos achar um par
    
    for(faceEscolhida = 0; faceEscolhida < TAMANHO_MAO * 2; faceEscolhida = faceEscolhida + 2)
    {
        for(faceComparada = faceEscolhida + 2; faceComparada < TAMANHO_MAO * 2; faceComparada = faceComparada + 2)
        {
            if (mao[faceEscolhida] == mao[faceComparada])
            {
                for(int faceComparada2 = faceComparada + 2; faceComparada2 < TAMANHO_MAO * 2; faceComparada2 = faceComparada2 + 2)
                {
                    if(mao[faceEscolhida] == mao[faceComparada2])
                    {
                        printf("Trinca achada: %s = %s = %s\n", face[mao[faceEscolhida]], face[mao[faceComparada]], face[mao[faceComparada2]]);   
                        return;
                    }
                }
            }
        }
    }
}

void imprimeCoordenadaMao(int mao[])
{
    for(int i = 0; i < TAMANHO_MAO * 2; i = i + 2)
        printf("face: %d, naipe: %d\n", mao[i], mao[i+1]);
}

