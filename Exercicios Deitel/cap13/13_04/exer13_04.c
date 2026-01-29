// Exercicio 13_04
// Este programa define uma macro com um argumento para calcular o volume de uma esfera. A aproximação utilizada é pi = 3.14159

#include <stdio.h>

#define PI 3.14159
#define CUBE(x) (x) * (x) * (x)
#define SPHERE_VOLUME(x) (4.0 / 3) * PI * CUBE(x) 

int main(void)
{
    int i; // contador
    
    printf("\n%-5s|%7s\n", "Raio", "Volume");
    
    for(i = 1; i <= 10; i++)
        printf("%5d %7.3f\n", i, SPHERE_VOLUME(i));
        
    putchar('\n');
}
