/***********************
 * Cálculo do valor intermédio de um conjunto de 3 valores lidos
 * Este algoritmo funciona bem na ocorrência de valores repetido
 * mas o mesmo não conteceria se em ves <= e >= nas comparações 
 * usássemos > e <.
 * 
 * O algaritmo também não escala bem. E se pretendessemos calcular a 
 * dos valores intermédios de um conjunto de 4 valores?
 * 
 * 
 * Autor: Jorge Martins
 * Data: 10/10/2022
 **********************************/

#include <stdio.h>


int main() {
    int i1, i2, i3;
    int middle;
    
    printf("3 números: ");
    scanf("%d%d%d", &i1, &i2, &i3);
    
    if ( (i1 >= i2 && i1 <= i3) || (i1 >= i3 && i1 <= i2)) { 
        middle = i1;
    }
    else if ((i2 >= i1 && i2 <= i3 ) || (i2 >= i3 && i2 <= i1)) {
            middle = i2;
    }
    else {
        middle = i3;
    }
    
    
    printf("middle = %d\n", middle);
    return 0;
}
