#pragma once

#include <stdbool.h>

#define STR_OK 0
#define EOL -1
#define OVERFLOW -2

/**
 * força todas as letra da string "str" para minúsculas
 */
void str_tolower(char str[]);  


/**
 * força todas as letra da string "str" para maíusculas
 */  
void str_toupper(char str[]);    


/**
 * retira os espaços iniciais e finais da string "str"
 */
void str_trim(char str[]);       


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
int str_next(const char line[], int *pos, char word[], int max_size);	  


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
int str_next_int(const char line[], int *pos, int *num);  
	 


 

    
