#include <stdbool.h>

/**
 * 
 * algumas funções para determinar o alterar características de caraters
 * semelhantes às declaradas no ficheiro de include <ctype.h>
 */
 
 
// verifica se o carater "c" é uma letra maíuscula
bool is_upper(int c) {
    if (c >= 'A' && c <= 'Z') return true;
    else return false;
    
    // return c >= 'A' && c <= 'Z';
}

// verifica se o carater "c" é uma letra minúscula
int is_lower(int c) {
    if ( c >= 'a' && c <= 'z' ) return true;
    else return false;
    
    // return c >= 'a' && c <= 'z';
}

// verifica se o carater "c" é uma letra 
int is_letter(int c) {
    if (is_lower(c) || is_upper(c)) return true;
    return false;
}

// converte para minúscula o caracter "c" caso seja uma letra maíuscula
int to_lower(int c) {
    if (!is_upper(c)) return c;
    return c + ('a' - 'A');
}

// converte para maíuscula o caracter "c" caso seja uma letra minúscula
int to_upper(int c) {
    if (!is_lower(c)) return c;
    return c - ('a' - 'A');
}
