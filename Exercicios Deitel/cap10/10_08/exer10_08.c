// Exercicio 10_08
// Esse programa testa o tipo definido por usuario union fazendo alguns testes sobre seus valores.

#include <stdio.h>
union integer
{
    char c;
    short s;
    int i;
    long b;
};

int main(void)
{
    union integer myUnionChar;
    union integer myUnionShort;
    union integer myUnionInt;    
    union integer myUnionLong; 
    
   printf("Digite um char, um short, um int e um long: ");
   scanf("%c %hd %d %ld", &myUnionChar.c, &myUnionShort.s, &myUnionInt.i, &myUnionLong.b);
   
   printf("Conteudo de myUnionChar\nc: %c\ns: %hd\ni: %d\nb: %ld\n\n", myUnionChar.c, myUnionChar.s, myUnionChar.i, myUnionChar.b);
   
   printf("Conteudo de myUnionShort\nc: %c\ns: %hd\ni: %d\nb: %ld\n\n", myUnionShort.c, myUnionShort.s, myUnionShort.i, myUnionShort.b);   
   
   printf("Conteudo de myUnionInt\nc: %c\ns: %hd\ni: %d\nb: %ld\n\n", myUnionInt.c, myUnionInt.s, myUnionInt.i, myUnionInt.b);     
   
   printf("Conteudo de myUnionLong\nc: %c\ns: %hd\ni: %d\nb: %ld\n\n", myUnionLong.c, myUnionLong.s, myUnionLong.i, myUnionLong.b);      
   
   return 0;
}
