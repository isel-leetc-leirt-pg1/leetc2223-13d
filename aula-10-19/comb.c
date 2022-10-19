#include <stdio.h>


long fatorial(int n) {
   
    long f = 1;
    while (n > 1) {
        f = f * n;
        n = n-1;
    }
    return f;
}


/**
 * Cálcula o total de combinações usando literalmente a fórmula.
 * Não funciona pois a função factorial rapidamente ultrapassa o alcance
 * dos tipos numéricos em C
 */
long ncomb(int n, int k) {
    return fatorial(n)/(fatorial(k)*fatorial(n-k));
}


/**
 * Versão realista do cálculo do número de combinações de N/K
 */
long ncomb2(int n, int k) {
    long lim = n -k;
    
    int prod = n;
    n= n-1;
    while( n > lim) {
        prod = prod*n;
        n = n-1;
    }
    
    return prod/fatorial(k);
}


/**
 * Apresenta na consola as combinações dois a dois
 * do conjunto de valores inteiros no intervalo
 * fechado [li,ls]
 */
void show_comb2(int li, int ls) {
    int n=1;
    int i = li;
    
    // A variável "j" declarada na linha 58 não está a ser usada entre as linhas 60  a 68.
    // Apenas ilustra a possibilidade de haver na linguagem C variáveis com o mesmo nome
    // em diferentes blocos das funcões. A declaração de j num bloco interior
    // (dentro do while) esconde a variável "j" declarada na linha 58.
    // Isto apenas serve como ilustração de uma característica da linguagem C.
    // Não usem variáveis com o mesmo nome em blocos aninhados (um dentro do outro),
    // embora possa usar em blocos independentes (um a seguir ao outro).
    int j = 10;
    
    printf("combinações de %d , 2 a 2:\n", (ls -li + 1));
    while (i < ls) {
        int j = i +1;
        while(j <= ls) {
            printf("%d: (%d, %d)\n", n, i, j);
            j = j+1;
            n = n+1;
        }
        i = i +1;
    }
    
    // acesso à variável "j" declarada na linha 55
    // Aqui não temos acesso à variável j declarada dentro bloco entre as linhas 60 a 68
    printf("j= %d\n", j);
}
       
       
int main() {
    show_comb2(1, 6);
    
    printf("total de comb(6,2)=%ld\n", ncomb2(6, 2));
     
    printf("total de comb(10000,2)=%ld\n", ncomb2(10000, 2));
    
    return 0;
}
