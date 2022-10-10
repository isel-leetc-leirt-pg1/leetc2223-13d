/***********************
 * Cálculo do média de uma sequência indeterminada de valores
 * lidos da consola. A sequência termina com um valor não numérico  
 * São descartados o menor e o maior valores da sequência lida.
 *  
 * 
 * Autor: Jorge Martins
 * Data: 10/10/2022
 **********************************/

#include <stdio.h>

int main() {
    int n = 0;      // total de valores lidos
    int sum = 0;    // soma dos valores lidos
    
    int val;        // cada valor lido
    
    int greatest;   // maior dos valores lidos
    int lowest;     // menor dos valores lidos
    
    printf("sequência de valores inteiros: ");
    
    // ler um primeiro valor para iniciar greatest e lowest com esse valor
    scanf("%d", &val);
    n = 1;
    sum = val;
    greatest = val;
    lowest = val;
    
    while(scanf("%d", &val) == 1) {
        
        // processar o valor lido
        sum = sum + val;
        n = n + 1;
        
        if (val > greatest) greatest = val;
        else if (val < lowest) lowest = val;
        
    }
    
    // apresentar resultados
    
    if (n < 3) {
        printf("tem de introduzir no mínimo 3 valores");
    }
    else {
        // descartar o maior e o menor valor da soma
        sum = sum - (greatest + lowest);
        n = n - 2;
        
        
        // o cast (float) na instrução seguinte
        // é necessário para realizar uma divisão real e não
        // uma divisão inteira quando o numerador e 
        // denominador são inteiros
        float mean =  ((float) sum )/ n;
        
        // apresentar com duas casas decimais
        printf("média=%.2f\n", mean);
    }
    return 0;
}
