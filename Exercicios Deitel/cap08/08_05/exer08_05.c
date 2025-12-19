// Exercicio 08_05
// Este programa testa cada função da biblioteca de tratamento de caractere (ctype.h) e imprime seu retorno como int.

#include <stdio.h>
#include <ctype.h>

int main(void)
{
    // Testa isdigit, isalpha, isalnum, isxdigit, islower, isupper, isspace, iscntrl, ispunct, isprint, isgraph
    char c;
    
    c = 'M';
    printf("Caractere %c:\n", c);
    printf("isdigit: %d.\n", isdigit(c));
    printf("isalpha: %d.\n", isalpha(c)); 
    printf("isalnum: %d.\n", isalnum(c));        
    printf("isxdigit: %d.\n", isxdigit(c));    
    printf("islower: %d.\n", islower(c));                
    printf("isupper: %d.\n", isupper(c));      
    printf("isspace: %d.\n", isspace(c)); 
    printf("iscntrl: %d.\n", iscntrl(c));        
    printf("ispunct: %d.\n", ispunct(c));    
    printf("isprint: %d.\n", isprint(c));                
    printf("isgraph: %d.\n", isgraph(c));           
    
    // Testa tolower, toupper   
    
    printf("tolower: %d.\n", tolower(c));                
    printf("toupper: %d.\n", toupper(c));   
    
}
