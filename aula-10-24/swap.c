#include <stdio.h>

/**
 * Primeiro exemplo de utilização de ponteiros na linguagem C
 * 
 * a função swap tem dois parâmetros que são ponteiros para interos (int *)
 * 
 * A utilização de ponteiros nos parâmetros da função permite
 * que estes funcionem como parâmetros de:
 *    saída ->  apenas é relevante o valor referido pelo argumento à saída da função
 *    entrada/saída -> o valor referido pelos argumentos é relevante
 *                     à entrada e à saída da função
 * 
 * Os parâmetros da função "swap" são de entrada/saída
 * A função troca os valores referidos pelos parâmetros
 * 
 */



void swap(int *n1, int *n2) {
    int aux;
    
    // apresenta os endereços dos parâmetros n1 e n2 
    printf("&n1=%p, &n2=%p\n", &n1, &n2);
    
    // apresenta o conteúdo ( que representa endereços) dos parâmetros n1 e n2
    // comparem com os endereços passados na chamada à função
    printf("n1=%p, n2=%p\n", n1, n2);
    
    // troca dos valores referidos por n1 e n2
    aux = *n1;
    *n1 = *n2;
    *n2 = aux;
    
    
    // apresenta os valores referidos pelos parâmetros após a troca
    printf("*n1 = %d, *n2 = %d\n", *n1, *n2);
}

int main() {
    int i1 = 3, i2 = 5;
    
    // apresenta os sendereços dos argumentos i1 e i2
    printf("&i1=%p, &i2=%p\n", &i1, &i2);
    swap(&i1, &i2);
    
     // apresenta os valores de i1 e i2 após a troca
    printf("i1 = %d, i2 = %d\n", i1, i2);
    
    return 0;
}
