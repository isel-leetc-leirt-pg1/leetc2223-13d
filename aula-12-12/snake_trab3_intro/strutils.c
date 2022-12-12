#include "strutils.h"

#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <stdio.h>





static int str_to_num(const char str[], int *num) {
    int signal = 1;
    int i = 0;
    long n= 0;
    
    if (str[0] == '+') { signal=1; i= 1; }
    else if (str[0] == '-') { signal = -1; i = 1; }
 
    if (!isdigit(str[i])) return -2;
    
	do {
		if (!isdigit(str[i])) return -2;
		n = n*10 + (str[i] - '0');
        ++i;
	}
    while(str[i]!= 0);

    n = n * signal;
    if (n < INT_MIN || n > INT_MAX) return OVERFLOW;
    *num = (int) n;
    return 0;
}


/**
 * força todas as letra da string "str" para minúsculas
 */
void str_tolower(char str[]) {
    int i=0;
    while(str[i] != 0) {
        str[i] = tolower(str[i]);
        ++i;
    }
}


/**
 * força todas as letra da string "str" para maíusculas
 */
void str_toupper(char str[]) {
    int i=0;
    while(str[i] != 0) {
        str[i] = toupper(str[i]);
        ++i;
    }
}


 

/**
 * retira os espaços iniciais e finais da string "str"
 */
void str_trim(char str[]) {
    const int len = strlen(str);
    int first = 0, last = len-1;
    if (last < 0) return; // empty string
    while(isspace(str[first])) first++;
    while (last >= first && isspace(str[last])) last--;
    
    if (first > 0) { // must copy from first to last to the beggining of string
        for(int d = 0, s=first; s <= last; ++s, ++d)  str[d] = str[s];
    }
    str[last+1-first] = 0;
}



/**
 * Coloca em "word" a próxima sequência de caracteres "não espaços" em "line",
 * de dimensão máxima "max_size"-1,  a partir da posição indicada por "pos",
 * saltando eventuais espaços iniciais.
 * O valor referido por "pos" é modificado para a posição do caracter imediatamente 
 * a seguir à sequeência retornada.
 * 
 * Retorna:
 *   0 em caso de sucesso
 *   EOL (-1) se não foi encontrado nenhum caracter "não espaço" até ao fim da string.
 *   OVERFLOW (-2)  se a sequência foi truncada por ser maior ou igual a max_size.
 * 
 */
int str_next(const char line[], int *pos, char word[], int capacity) {
	int i= *pos;
	
	// jump separators
	while(isspace(line[i])) ++i;
	
	// get the line
	char c= line[i];
	int p = 0;
	while( p < capacity-1 && !isspace(line[i]) && c != 0 ) {
		word[p++] = c;
		++i;
		c = line[i];
	};
	word[p]=0;
	
	// if no word exists or word was cutted, fail the operation
	if (p == 0  && c == 0) return -1; // EOF
    if (p == capacity-1 && !isspace(c) && c!= 0) 
        return -2; // OVERFLOW
    *pos = i;
    
    //printf("token='%s'\n", word);
	return 0;
}


/**
 * Afeta o inteiro referido por "num", com o valor obtido da sequência  
 * de dígitos em "line", a partir da posição indicada por "pos",
 * saltando eventuais espaços iniciais.
 * O valor referido por "pos" é modificado para a posição do caracter imediatamente 
 * a seguir à sequència de dígitos correspondente ao inteiro obtido.
 * 
 * Retorna:
 *   0 em caso de sucesso
 *   EOL (-1) se não foi encontrado nenhum caracter "não espaço" até ao fim da string.
 *   OVERFLOW (-2) se o número é demasiado grande para caber num inteiro.
 * 
 */
int str_next_int(const char line[], int *pos, int *num) {
	char str_num[12];
	int res;
	 
 	
    if ((res =str_next(line, pos, str_num, sizeof(str_num))) < 0)
        return res;
    
    //printf("token: '%s'\n", str_num);
    return str_to_num(str_num, num);
}

 












