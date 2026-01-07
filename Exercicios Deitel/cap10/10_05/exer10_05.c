// Exercicio 10_05
// 
#include <stdio.h>
// a
struct
{
    char nomePeca[30];
    int numPeca;
    float preco;
    int quantidade;
    int pedido;
} typedef Estoque;

// b
union 
{
    char c;
    short s;
    long b;
    float f;
    double d;
} typedef Dados;

struct
{
    char rua[25], cidade[20], estado[2], cep[8];
} typedef Endereco;

struct
{
    char nome[15];
    char sobrenome[15];
    Endereco endResid;
} typedef Aluno;

struct
{
    unsigned a : 1;
    unsigned b : 1;    
    unsigned c : 1;    
    unsigned d : 1;    
    unsigned e : 1;    
    unsigned f : 1;    
    unsigned g : 1;    
    unsigned h : 1;    
    unsigned i : 1;    
    unsigned j : 1;    
    unsigned k : 1;    
    unsigned l : 1;    
    unsigned m : 1;    
    unsigned n : 1;    
    unsigned o : 1;    
    unsigned p : 1;    
        
} typedef Teste;

int main(void)
{

}



