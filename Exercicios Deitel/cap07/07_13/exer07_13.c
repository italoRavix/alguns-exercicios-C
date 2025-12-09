// Exercicio 07_13
// Programa de embralhamento e distribuição de cartas
//
// Minha ideia para esse exercicio consistiu em criar um array inteiro mao com 10 inteiros e armazenar nele
// as faces (indices pares) e naipes (indices impares) das 5 primeiras cartas sorteadas que representam uma mão.
// Como exemplo, a carta 'Rei de Copas' seria armazenada no array assim: um inteiro 12 no indice i e um inteiro 0 no indice i+1.
//
// Para comparar as mao de poker eu decidi atribuir valores de pontuação a cada tipo de mão. Para isso mudei o retorno das funçoes
// que avaliam o tipo de mão de void para int.


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO_MAO 5
#define NUMERO_FACES 13
#define NUMERO_NAIPES 4

// pontuaçoes
#define NADA 0
#define UM_PAR 1
#define DOIS_PARES 2
#define TRINCA 3
#define QUADRA 4
#define FLUSH 5
#define STRAIGHT 6

// prototipos
void embaralha(int[][13]);
void distribui(const int baralho[][13], const char *naipe[], const char *face[], int mao[]);
void distribui2(const int baralho[][13], const char *naipe[], const char *face[], int mao[]); // adicionada para distribuir para o segundo jogador

// prototipos para funçoes das questoes do exercicio 12
int verificaUmPar(int mao[], const char *face[]);
int verificaDoisPares(int mao[], const char *face[]);
int verificaUmaTrinca(int mao[], const char *face[]);
int verificaQuadra(int mao[], const char *face[]);
int verificaFlush(int mao[], const char *naipe[]);
int verificaStraight(int mao[], const char *face[]);
void imprimeCoordenadaMao(int mao[]);
void bubbleSort(int mao[]);

// prototipos para funçoes das questoes
void printMao(int mao[], const char *face[], const char *naipe[]);
void distribuiDuasPessoas(const int baralho[][NUMERO_FACES], const char *naipe[], const char *face[], int mao1[], int mao2[]);

int main(void)
{
    // inicializa array naipe
    const char *naipe[NUMERO_NAIPES] = {"Copas", "Ouro", "Paus", "Espadas"};
    
    // inicializa array faces
    const char *face[NUMERO_FACES] = {"Ás", "Dois", "Tres", "Quatro", "Cinco", "Seis", "Sete", "Oito", "Nove", "Dez", "Valete", "Dama", "Rei"}; 
    
    // inicializa o array que representa a mao
    int mao1[10];
    int mao2[10];
    
    // inicializa array baralho
    int baralho[NUMERO_NAIPES][NUMERO_FACES] = {0};   
    
    srand(time (0)); // semente do gerador de numero aleatorio
    
    embaralha(baralho);
    
    //distribui(baralho, naipe, face, mao1);  
    //printf("\n");
    //distribui2(baralho, naipe, face, mao2);
    //printf("\n");
    //imprimeCoordenadaMao(mao2);
    
    distribuiDuasPessoas(baralho, naipe, face, mao1, mao2);
    
    printMao(mao1, face, naipe);
    printMao(mao2, face, naipe);
    
}

void embaralha(int baralho[][NUMERO_FACES])
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
void distribui(const int baralho[][NUMERO_FACES], const char *naipe[], const char *face[], int mao[])
{
    int carta;
    int linha;
    int coluna;
    
    // distribui cada uma das 5 cartas de uma mao de poker
    for(carta = 1; carta <= TAMANHO_MAO; carta++)
    {
        // loop pelas linhas de baralho
        for(linha = 0; linha < NUMERO_NAIPES; linha++)
        {
            // loop pelas colunas de baralho
            for(coluna = 0; coluna < NUMERO_FACES; coluna++)
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

// distribui cartas do baralho em uma mão
void distribui2(const int baralho[][NUMERO_FACES], const char *naipe[], const char *face[], int mao[])
{
    int carta;
    int linha;
    int coluna;
    
    // distribui cada uma das 5 cartas de uma mao de poker
    for(carta = 6; carta <= TAMANHO_MAO * 2; carta++)
    {
        // loop pelas linhas de baralho
        for(linha = 0; linha < NUMERO_NAIPES; linha++)
        {
            // loop pelas colunas de baralho
            for(coluna = 0; coluna < NUMERO_FACES; coluna++)
            {
                //printf("%d\n", baralho[linha][coluna]);
                
                // se slot contem a carta atual, mostra a carta
                if(baralho[linha][coluna] == carta)
                {
                    printf("%s de %s %c", face[coluna], naipe[linha], '\n');
                    
                    // as duas instruçoes a seguir foram adicionas para solucionar os exercicios
                    mao[(carta - 6) * 2] = coluna; //armazena a coordenada da coluna nos indices pares (faces)
                    mao[(carta - 5) * 2 - 1] = linha; // armazena a coordenada da linha nos indices impares (naipes)
                }    
            }
        }   
    }
}

// a
// verifica se há um par na mao 
int verificaUmPar(int mao[], const char *face[])
{
    int faceEscolhida; // armazena a face escolhida para ser comparada
    int faceComparada; // armazena as faces que serao comparadas com a escolhida
    
    for(faceEscolhida = 0; faceEscolhida < TAMANHO_MAO * 2; faceEscolhida = faceEscolhida + 2)
    {
        for(faceComparada = faceEscolhida + 2; faceComparada < TAMANHO_MAO * 2; faceComparada = faceComparada + 2)
        {
            if (mao[faceEscolhida] == mao[faceComparada])
            {
                return UM_PAR;
            }
        }
    }
    
    return NADA;
}

// b
// verifica se há dois pares na mao 
int verificaDoisPares(int mao[], const char *face[])
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
                facePrimeiroPar = mao[faceEscolhida];
                if(existeUmPar)
                  return DOIS_PARES;
                
                existeUmPar = 1;
            }
        }
    }
    
    return NADA;
}

// c
// verifica se há uma trinca na mao 
int verificaUmaTrinca(int mao[], const char *face[])
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
                        return TRINCA;
                }
            }
        }
    }
    
    return NADA;
}

//d
// verifica se há uma quadra na mao
int verificaQuadra(int mao[], const char *face[])
{
    int faceEscolhida; // a cada iteraçao representa uma face diferente
    int indiceMao; // armazena o indice a ser comparado na mao
    int contadorFace; // conta o numero de faces iguais encontradas
    
    for(faceEscolhida = 0; faceEscolhida < NUMERO_FACES; faceEscolhida++)
    {
        contadorFace = 0;
        for(indiceMao = 0; indiceMao < TAMANHO_MAO * 2; indiceMao = indiceMao += 2)
        {
            if(faceEscolhida == mao[indiceMao])
                contadorFace++;
            
            if(contadorFace == 4)
                return QUADRA;
        }
    } 
    
    return NADA;
}

//e
// verifica se há um flush na mao
int verificaFlush(int mao[], const char *naipe[])
{
    int naipeEscolhido; // a cada iteraçao representa um naipe diferente
    int indiceMao; // armazena o indice a ser comparado na mao
    int contadorNaipe; // conta o numero de naipes iguais encontrados
    
    for(naipeEscolhido = 0; naipeEscolhido < NUMERO_NAIPES; naipeEscolhido++)
    {
        contadorNaipe = 0;
        for(indiceMao = 1; indiceMao < TAMANHO_MAO * 2; indiceMao = indiceMao += 2)
        {
            if(naipeEscolhido == mao[indiceMao])
                contadorNaipe++;
            
            if(contadorNaipe == 5)
                return FLUSH;
        }
    } 
    
    return NADA;
}

//f 
// verifica se há straight na mao
int verificaStraight(int mao[], const char *face[])
{
    int indiceFace1 = (TAMANHO_MAO * 2) - 4; // seleciona o penultimo indice de uma face na mao
    int indiceFace2 = (TAMANHO_MAO * 2) - 2; // seleciona o ultimo indice de uma face na mao
    int contadorFace = 0;
    
    bubbleSort(mao);
    while(mao[indiceFace2] - mao[indiceFace1] == 1 && mao[indiceFace1] >= 0) // analisa se a difenrença entre duas faces é sempre 1, o que indica que sao sonsecutivas
    {
        contadorFace++;
        indiceFace2 -= 2;
        indiceFace1 -= 2;
    }
    
    if(contadorFace == 4)
        return STRAIGHT;
    
    return NADA;
}

void imprimeCoordenadaMao(int mao[])
{
    for(int i = 0; i < TAMANHO_MAO * 2; i = i + 2)
        printf("face: %d, naipe: %d\n", mao[i], mao[i+1]);
}

void bubbleSort(int mao[])
{
    int pass; // contador de passada
    int i; // contador de comparaçao
    int holdFace; // local temporario usado para trocar elementos do array
    int holdNaipe;
    
    for(pass = 0; pass < TAMANHO_MAO * 2; pass = pass + 2)
    {
        for(i = 0; i < (TAMANHO_MAO * 2) - 2; i = i + 2)
        {
            if(mao[i] > mao[i + 2])
            {
                holdFace = mao[i];
                holdNaipe = mao[i + 1];
                
                mao[i] = mao[i + 2];
                mao[i + 1] = mao[i + 3];
                
                mao[i + 2] = holdFace;
                mao[i + 3] = holdNaipe;
            }
        }
    }
}

// imprime o tipo de mao de um jogador
void printMao(int mao[], const char *face[], const char *naipe[])
{   
    if(verificaStraight(mao, face))
    {
        printf("Straight achado\n");
        return;
    }      
    
    if(verificaFlush(mao, naipe))
    {
        printf("Flush achado\n");
        return;
    }      
    
    if(verificaQuadra(mao, face))
    {
        printf("Quadra achada\n");
        return;
    }     
    
    if(verificaUmaTrinca(mao, face))
    {
        printf("Trinca achada\n");
        return;
    }    
    
    if(verificaDoisPares(mao, face))
    {
        printf("Dois pares achados\n");
        return;
    } 
    
    if(verificaUmPar(mao, face))
    {
        printf("Par achado\n");
        return;
    }    
    
        printf("Nada achado\n");
}

// avalia a pontuaçao de um jogador
int resultado(int mao[], const char *face[], const char *naipe[])
{   
    int resultado; // armazena a pontuaçao do jogador
    
    resultado = verificaStraight(mao, face);
    if(resultado)
    {
        return resultado;
    }      
    
    resultado = verificaFlush(mao, naipe);
    if(resultado)
    {
        return resultado;
    }   
    
    resultado = verificaQuadra(mao, face);
    if(resultado)
    {
        return resultado;
    }  
    
    resultado = verificaUmaTrinca(mao, face);
    if(resultado)
    {
        return resultado;
    }      
    
    resultado = verificaUmaTrinca(mao, face);
    if(resultado)
    {
        return resultado;
    }   
    
    resultado = verificaDoisPares(mao, face);
    if(resultado)
    {
        return resultado;
    }    
    
    resultado = verificaUmPar(mao, face);
    if(resultado)
    {
        return resultado;
    }       
    
    return NADA;
}

// Faz a simulacao de distribuiçao de cartas entre duas pessoas
void distribuiDuasPessoas(const int baralho[][NUMERO_FACES], const char *naipe[], const char *face[], int mao1[], int mao2[])
{
    int resultado1;
    int resultado2;
    
    distribui(baralho, naipe, face, mao1);  
    printf("\n");
    resultado1 = resultado(mao1, face, naipe);
    
    distribui2(baralho, naipe, face, mao2);  
    printf("\n");
    resultado2 = resultado(mao2, face, naipe);    
    
    if(resultado1 > resultado2)
        printf("Jogador 1 venceu\n");
    else if(resultado2 > resultado1)
        printf("Jogador 2 venceu\n");
    else
        printf("Empate\n");
}
