/********************************************************
 * Implementação simplificada de algumas funções descritas
 * em <string.h>
 * 
 ********************************************************/
#include <stdio.h>

// retorna a dimensão (número de carateres da string "s"
int mstrlen(const char s[]) {
    int i = 0;
    while(s[i] != 0) i++;
    return i;
}

// copia a string "src" para a string "dst"
void mstrcpy(char dst[], const char src[]) {
    int i= 0;
    
    while((dst[i] = src[i]) != 0) ++i;
}


// acrescenta à string "s1" a string "s2"
void mstrcat(char s1[], const char s2[]) {
    int i1 = mstrlen(s1), i2 = 0;
    
    while( (s1[i1] = s2[i2]) != 0) { 
        ++i1; 
        ++i2 ;
    } 
}


int main() {
   
}
    
    
    
    
    
    
    
    
    
