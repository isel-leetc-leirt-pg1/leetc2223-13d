/***********************
 * Cálculo do valor intermédio de um conjunto de 3 valores lidos
 * por determinação do menor e do maior.
 * 
 * Este algoritmo funciona bem na ocorrência de valores repetidos
 * mas não escala bem. E se pretendessemos calcular a 
 * dos valores intermédios de um conjunto de 4 valores?
 * 
 * 
 * Autor: Jorge Martins
 * Data: 10/10/2022
 **********************************/

#include <stdio.h>


int main() {
    int i1, i2, i3;
    int middle, lowest, greatest;
    
    printf("3 números: ");
    scanf("%d%d%d", &i1, &i2, &i3);
    
    if (i1 > i2) {
        if (i1 > i3) greatest = i1;
        else greatest = i3;
    }
    else {
        if (i2 > i3) greatest = i2;
        else greatest = i3;
    }
    
    if (i1 < i2) {
        if (i1 < i3) lowest = i1;
        else lowest = i3;
    }
    else {
        if (i2 < i3) lowest = i2;
        else lowest = i3;
    }
    
    middle = (i1 + i2 + i3) - (lowest + greatest);
    
    
    printf("middle = %d\n", middle);
    return 0;
}
