// Exercicio 10_14
// 

#include <stdio.h>
#include "../General Functions/functions_10.h"

int main(void)
{
    char c[2], *cPtr;
    
    // recebe os chars compactados
    unsigned short packedChars = packCharacters('m', '\\');
    
    // recebe os chars desconpactados
    cPtr = unpackCharacters(packedChars, c);
    
    displayBits(packedChars, TYPE_U_SHORT);    
    displayBits(cPtr[0], TYPE_CHAR);
    displayBits(cPtr[1], TYPE_CHAR);    
        
    return 0;
}
