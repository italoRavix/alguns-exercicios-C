// Exercicio 10_16
// Este programa cria um baralho usando um array de estruturas card, o imprime, embaralha e o imprime novamente.
// 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52
#define FACES_NUMBER 13
#define SUITS_NUMBER 4
#define COLOR_NUMBER 2

struct bitCard {
    unsigned face: 4;
    unsigned suit: 2;
    unsigned color : 1;
};

typedef struct bitCard Card;

// prototipos
void fillDeck( Card * const wDeck );
void shuffle( Card * const wDeck );
void deal( const Card * const wDeck , char *colors[], char *faces[], char *suits[]);


int main(void)
{
    Card deck[DECK_SIZE];
    
char *faces[FACES_NUMBER] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Queen", "Jack", "King"};

    char *suits[SUITS_NUMBER] = {"Spades", "Clubs", "Hearts", "Diamonds"};
    
    char *colors[COLOR_NUMBER] = {"Black", "Red"};    
  
    srand(time(NULL));
    
    fillDeck(deck);
    deal(deck, colors, faces, suits);
    putchar('\n');
    shuffle(deck);
    deal(deck, colors, faces, suits);  
}

// coloca strings nas estruturas Card 
void fillDeck(Card * const wDeck )
{
    int i; // contador
    
    // loop por wDeck
    for(i = 0; i < DECK_SIZE; i++)
    {
        wDeck[i].face = i % 13;
        wDeck[i].suit = i / 13;      
        wDeck[i].color = i / 26;
    }
}


// embaralha as cartas
void shuffle( Card * const wDeck )
{
    int i; // contador
    int j; // variavel para manter valor aleatorio entre 0-51
    Card temp; // declara estrutura temporaria para trocar as cartas
    
    // loop por wDeck trocando cartas aleatoriamente
    for(i = 0; i < DECK_SIZE; i++)
    {
        j = rand() % DECK_SIZE;
        
        temp = wDeck[i];
        wDeck[i] = wDeck[j];
        wDeck[j] = temp;
    }
}

// distribui as cartas
void deal( const Card * const wDeck , char *colors[], char *faces[], char *suits[])
{
    int i; // subscritos de 0-25
    int j; // subscritos 26-51
    
    for(i = 0, j = i + DECK_SIZE / 2; j < DECK_SIZE; i++, j++)
    {
        printf("%-5s: %-5s of %-6s %c", colors[wDeck[i].color], faces[wDeck[i].face], suits[wDeck[i].suit], '|');    
        printf(" %-5s: %-5s of %-6s %c", colors[wDeck[j].color], faces[wDeck[j].face], suits[wDeck[j].suit], '\n');  
    }
}
