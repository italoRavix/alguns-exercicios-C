// Exercicio  10_06
// Testes de acesso a membros via operador ponto (.) e operador seta (->)

#include<stdio.h>

struct cliente {
    char nome[ 15 ];
    char sobrenome[ 15 ];
    int numCliente;
    
    struct {
        char telefone[ 11 ];
        char endereco[ 50 ];
        char cidade[ 25 ];
        char estado[ 2 ];
        char cep[ 8 ];
    } pessoal;
    
    } regCliente = {"Italo", "Reus", 11, {"3899999999", "Rua dos Santos", "Diamantina", "MG", "39100000"}}, *ptrCliente = &regCliente;

int main(void)
{   
    // a
    printf("A: %s\n", regCliente.sobrenome);
    
    // b
    printf("B: %s\n", ptrCliente->sobrenome);
    
    // c
    printf("C: %s\n", regCliente.nome);
    
    // d
    printf("D: %s\n", ptrCliente->nome);    
    
    // e
    printf("E: %d\n", regCliente.numCliente);
    
    // f
    printf("F: %d\n", ptrCliente->numCliente);    
    
    // g
    printf("G: %s\n", regCliente.pessoal.telefone);  
    
    // h
    printf("H: %s\n", ptrCliente->pessoal.telefone);  
    
    // i
    printf("I: %s\n", regCliente.pessoal.endereco);  
    
    // j
    printf("J: %s\n", ptrCliente->pessoal.endereco);
    
    // k
    printf("K: %s\n", regCliente.pessoal.cidade);
    
    // l
    printf("L: %s\n", ptrCliente->pessoal.cidade);    
    
    // m
    printf("M: %s\n", regCliente.pessoal.estado);  
    
    // n
    printf("N: %s\n", ptrCliente->pessoal.estado);  
    
    // o
    printf("O: %s\n", regCliente.pessoal.cep);  
    
    // p
    printf("P: %s\n", ptrCliente->pessoal.cep);    
}
