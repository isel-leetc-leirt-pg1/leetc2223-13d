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

// compara a string "s1" com a string "s2"
int mstrcmp(const char s1[], const char s2[]) {
    int i = 0;
    
    // a verificação da terminação de s1 (s1[i] !=0 ) é 
    // necessário para o caso das strings serem exatamente iguais
    while(s1[i] != 0 && s1[i] == s2[i]) ++i;
    return s1[i] - s2[i];
}


// verifica se a string "line" contém a string "pattern"
// return a posição em "line" onde a "pattern" existe ou -1
// se "pattern" não existir

int mstrstr(const char line[], const char pattern[]) {
    int i=0; // posição em line
    int lim = mstrlen(line) - mstrlen(pattern);
    
    
    while (i <= lim) {
        int j = 0;
        while(line[i+j] == pattern[j] && pattern[j] != 0) {
            j++;
        }
        if (pattern[j] == 0) {
            return i;
        }
        i++;
    }
    
    return -1;
}



/*
 * O main (com código de teste) foi posto em comentário 
 * para permitir usar estas funções em outros programas
 * (num programa só pode haver uma funçã main!)
 * O que seria masoi correto era colocar este código de teste
 * num ficheiro à parte
*/

/**----------------------------------------------------------
 
int main() {
    int expected_pos = 11;
    int pos = mstrstr("a line contains words", "ains");
    if (pos == expected_pos) printf("teste 1 ok!\n");
    else printf("error on teste 1!\n");
    
    char text[] = { 'a', 'b', 'c', 0 };
    char pattern1[]  = { 'c', 0 };
    
    pos = mstrstr(text, pattern1);
    expected_pos = 2;
    if (pos == expected_pos) printf("teste 2 ok!\n");
    else printf("error on teste 2!\n");
    
    char pattern2[] = {'c', 'a' , 0 };
    
    pos = mstrstr(text, pattern2);
    expected_pos = -1;
    if (pos == expected_pos) printf("teste 3 ok!\n");
    else printf("error on teste 3!\n");
    
    
    return 0;
}

---------------------------------------------------------*/
    
    
    
    
    
    
    
