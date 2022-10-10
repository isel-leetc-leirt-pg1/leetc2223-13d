/***********************
 * Cálculo do valor intermédio de um conjunto de 3 valores lidos
 * por determinação do menor e do maior.
 * 
 * Este algoritmo funciona bem na ocorrência de valores repetidos
 * e escala melhor do que os outros. Para um conjunto de 4 valores
 * seria acrescentar duas linhas para comparar o 4º valor com 
 * o menor e o maior
 * 
 * E se pretendesse lidar com um conjunto indeterminado de valores lidos da consola? 
 * Nesse caso teríamos de usar intsruções de ciclo
 * que iremos ver a seguir 
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
    
    greatest = i1;
    if (i2 > greatest) greatest = i2;
    if (i3 > greatest) greatest = i3;
    
    lowest = i1;
    if (i2 < lowest) lowest = i2;
    if (i3 < lowest) lowest = i3;

    middle = (i1 + i2 + i3) - (lowest + greatest);
    printf("middle = %d\n", middle);
    return 0;
}
