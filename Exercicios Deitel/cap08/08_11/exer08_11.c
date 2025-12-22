// Exercicio 08_11
// Este programa usa 5 arrays para gerar sentenças aleatorias.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

// definições
#define ARTICLE_SIZE 6
#define NOUM_SIZE 5
#define VERB_SIZE 5
#define PREPOSITION_SIZE 5
#define PHRASE_NUMBER_WORDS 6
#define PHRASE_SIZE_MAX 100
#define SENTENCES_NUMBER 20

// protótipos
char *createPhrase(char **article, char **noum, char **verb, char **preposition, int articleSize, int noumSize, int verbSize, int prepositionSize, char* phraseSlot);
char *randomWord(char **palavras, int length);
int randomIndex(int length);
char *upperFirstLetter(char *word);

int main(void)
{
    // cria os arrays com as palavras
    char *artigo[ARTICLE_SIZE] = {"o", "a", "um", "uma", "algum", "alguma"};
    char *substantivo[NOUM_SIZE] = {"menino", "menina", "cão" , "cidade", "carro"};
    char *verbo[VERB_SIZE] = {"dirigiu", "saltou", "correu", "caminhou", "saltou"};
    char *preposicao[PREPOSITION_SIZE] = {"para", "de", "sob", "sobre", "em"};
    char phrase[PHRASE_SIZE_MAX]; // armazenara a frase
    
    char *createdPhrase; // usado para tornar o printf menos poluido visualmente
    
    for (int i = 0; i < SENTENCES_NUMBER; i++)
    {
        // armazena a frase gerada
        sleep(1); // faz o sistema parar um segundo para que srand funcione corretamente
        
        createdPhrase = createPhrase(artigo, substantivo, verbo, preposicao, ARTICLE_SIZE, NOUM_SIZE, VERB_SIZE, PREPOSITION_SIZE, phrase);
        printf("%s", createdPhrase);
    }
    
    return 0;
}

// cria a frase aleatoria
char *createPhrase(char **article, char **noum, char **verb, char **preposition, int articleSize, int noumSize, int verbSize, int prepositionSize, char* phraseSlot)
{
    phraseSlot[0] = '\0'; //limpa o array para adicionar a nova sentença
    srand(time(NULL)); // pega o horario do sistema para geração aleatoria
    
    strcat(phraseSlot, randomWord(article, articleSize));
    strcat(phraseSlot, " ");    
    strcat(phraseSlot, randomWord(noum, noumSize));  
    strcat(phraseSlot, " ");
    strcat(phraseSlot, randomWord(verb, verbSize));
    strcat(phraseSlot, " ");
    strcat(phraseSlot, randomWord(preposition, prepositionSize));    
    strcat(phraseSlot, " ");
    strcat(phraseSlot, randomWord(article, articleSize));
    strcat(phraseSlot, " ");
    strcat(phraseSlot, randomWord(noum, noumSize));
    strcat(phraseSlot, ". ");
    
    upperFirstLetter(phraseSlot);
    
    return phraseSlot;    
}

// seleciona uma palavra do array
char *randomWord(char **palavras, int length)
{
    return palavras[randomIndex(length)];
}

// gera um inteiro aleatorio entre 0 e o numero passado como argumento (inclusive)
int randomIndex(int number)
{
    return rand() % number;
}

// faz a primeira letra de um array de char ser maiuscula
char *upperFirstLetter(char *word)
{
    word[0] = toupper(word[0]); // obtem a primeira letra de word, converte em maiuscula e coloca-a de volta em word
    
    return word;
}
